#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#define MAX_CMD_STR 100

char *arg[3];
int cnt = 1;

void sig_chld(int signo)
{
    int pid, status;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        cnt++;
    }
}

int echo_rqt(int sockfd, int pin, FILE *wr_in)
{
    char buf[MAX_CMD_STR];
    sprintf(buf, "td%d.txt", pin);
    FILE *f = fopen(buf, "r");

    pin = htonl(pin);

    int tmp;

    int len_h = 0;
    int len_n = 0;
    int res = -1;

    bzero(buf, sizeof(buf));

    while (fgets(buf, MAX_CMD_STR, f))
    {
        if (strncmp(buf, "exit", 4) == 0)
            break;
        len_h = strnlen(buf, MAX_CMD_STR);
        buf[len_h - 1] = '\0';

        write(sockfd, &pin, sizeof(pin));
        len_h = htonl(len_h);
        write(sockfd, &len_h, sizeof(len_h));
        len_h = ntohl(len_h);
        write(sockfd, buf, len_h);

        bzero(buf, sizeof(buf));

        read(sockfd, &tmp, sizeof(pin));
        tmp = ntohl(tmp);
        read(sockfd, &len_n, sizeof(len_n));
        len_n = ntohl(len_n);

        len_h = 0;
        do
        {
            res = read(sockfd, buf + len_h, len_n);
            len_h += res;
        } while (len_h < len_n && res > 0);

        char wr[MAX_CMD_STR + 50];
        bzero(wr, sizeof(wr));
        sprintf(wr, "[echo_rep](%d) %s\n", getpid(), buf);
        fwrite(wr, strlen(wr), 1, wr_in);

        bzero(buf, sizeof(buf));
    }
    pin = ntohl(pin);

    close(sockfd);
    bzero(buf, sizeof(buf));
    sprintf(buf, "[cli](%d) connfd is closed!\n", getpid());
    fwrite(buf, strlen(buf), 1, wr_in);

    bzero(buf, sizeof(buf));
    sprintf(buf, "[cli](%d) %s process is going to exit!\n", getpid(), (pin == 0 ? "parent" : "child"));
    fwrite(buf, strlen(buf), 1, wr_in);

    fclose(f);
    fclose(wr_in);
    printf("[cli](%d) stu_cli_res_%d.txt is closed!\n", getpid(), pin);
    return pin;
}

void new_child(int PIN)
{
    char buf[50];
    char res[MAX_CMD_STR];
    sprintf(buf, "stu_cli_res_%d.txt", PIN);
    FILE *fd = fopen(buf, "w");
    printf("[cli](%d) %s is created!\n", getpid(), buf);
    bzero(buf, sizeof(buf));
    sprintf(buf, "[cli](%d) child process %d is created!\n", getpid(), PIN);
    fwrite(buf, strlen(buf), 1, fd);

    struct sockaddr_in local;
    bzero(&local, sizeof(local));
    local.sin_family = AF_INET;
    inet_pton(AF_INET, arg[1], &local.sin_addr.s_addr);
    local.sin_port = htons(atoi(arg[2]));

    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(connfd, (struct sockaddr *)&local, sizeof(local));
    bzero(buf, sizeof(buf));
    inet_ntop(AF_INET, &local.sin_addr, buf, sizeof(local));
    sprintf(res, "[cli](%d) server[%s:%d] is connected!\n", getpid(), buf, ntohs(local.sin_port));
    fwrite(res, strlen(res), 1, fd);

    echo_rqt(connfd, PIN, fd);
    close(connfd);
    exit(0);
}

void fork_all(int PIN, int max_proc)
{
    pid_t pid = fork();
    if (pid == 0)
        new_child(PIN);
    else
    {
        if (PIN + 1 != max_proc)
            fork_all(PIN + 1, max_proc);
        else
        {
            PIN = 0;
            char* buf;
            char res[MAX_CMD_STR];
            sprintf(buf, "stu_cli_res_%d.txt", PIN);
            FILE *fd = fopen(buf, "w");
            printf("[cli](%d) %s is created!\n", getpid(), buf);
            // bzero(buf, sizeof(buf));
            // sprintf(buf, "[cli](%d) parent process %d is created!\n", getpid(), PIN);
            // fwrite(buf, strlen(buf), 1, fd);

            struct sockaddr_in local;
            bzero(&local, sizeof(local));
            local.sin_family = AF_INET;
            inet_pton(AF_INET, arg[1], &local.sin_addr.s_addr);
            local.sin_port = htons(atoi(arg[2]));

            int connfd = socket(AF_INET, SOCK_STREAM, 0);
            connect(connfd, (struct sockaddr *)&local, sizeof(local));
            bzero(buf, sizeof(buf));
            inet_ntop(AF_INET, &local.sin_addr, buf, sizeof(local));
            sprintf(res, "[cli](%d) server[%s:%d] is connected!\n", getpid(), buf, ntohs(local.sin_port));
            fwrite(res, strlen(res), 1, fd);

            echo_rqt(connfd, PIN, fd);
            while (cnt < max_proc)
            {
                pause();
            }
            close(connfd);
            exit(0);
        }
    }
}

int main(int argc, char *argv[])
{
    arg[1] = argv[1];
    arg[2] = argv[2];

    int max_proc = atoi(argv[3]);
    int PIN = 0;

    struct sigaction act;
    bzero(&act, sizeof(act));
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_flags |= SA_RESTART;
    act.sa_handler = &sig_chld;
    sigaction(SIGCHLD, &act, NULL);

    fork_all(PIN + 1, max_proc);
    return 0;
}
