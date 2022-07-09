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
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#define MAX_CMD_STR 100

int sig_to_exit = 0;
int sig_type = 0;

void sig_pipe(int signo)
{
    sig_type = SIGPIPE;
    printf("[srv](%d) SIGPIPE is coming!\n", getpid());
}
void sig_int(int signo)
{
    FILE *fd = fopen("stu_srv_res_p.txt", "a");
    char buf[MAX_CMD_STR];
    sprintf(buf, "[srv](%d) SIGINT is coming!\n", getpid());
    fwrite(buf, strlen(buf), 1, fd);
    fclose(fd);

    sig_type = SIGINT;
    sig_to_exit = 1;
}
void sig_chld(int signo)
{
    sig_type = SIGCHLD;
    int pid, status;
    FILE *fd = fopen("stu_srv_res_p.txt", "a");
    char buf[MAX_CMD_STR];
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        sprintf(buf, "[srv](%d) SIGCHLD is coming!\n", getpid());
        fwrite(buf, strlen(buf), 1, fd);
        printf("[srv](%d) server child(%d) terminated.\n", getpid(), pid);
    }
    fclose(fd);
}

int echo_rep(int sockfd, FILE *fd)
{
    int pin;

    int res = -1;
    int len_h = 0;
    int len_n = 0;

    while (!sig_to_exit)
    {
        res = read(sockfd, &pin, sizeof(pin));
        if (res == 0)
            break;
        if (res < 0)
        {
            if (errno == EINTR)
            {
                if (sig_type == SIGINT)
                    break;
                continue;
            }
            break;
        }
        res = read(sockfd, &len_n, sizeof(len_n));
        len_n = ntohl(len_n);

        
        if (res < 0)
        {
            if (errno == EINTR)
            {
                if (sig_type == SIGINT)
                    break;
                continue;
            }
            break;
        }

        len_h = 0;
        char buf[len_n + 1];
        bzero(buf, sizeof(buf));
        do
        {
            res = read(sockfd, buf + len_h, len_n);
            len_h += res;
        } while (len_h + 1 < len_n && res > 0);
        if (res < 0)
        {
            if (errno == EINTR)
            {
                if (sig_type == SIGINT)
                    break;
                continue;
            }
            free(buf);
            break;
        }
        char res[MAX_CMD_STR + 50];
        sprintf(res, "[echo_rqt](%d) %s\n", getpid(), buf);
        fwrite(res, strlen(res), 1, fd);

        write(sockfd, &pin, sizeof(pin));
        len_h = htonl(len_h);
        write(sockfd, &len_h, sizeof(len_h));
        len_h = ntohl(len_h);
        write(sockfd, buf, len_h);
    }
    pin = ntohl(pin);
    return pin;
}

void new_chld(int connfd)
{
    char fn_res[20];
    sprintf(fn_res, "stu_srv_res_%d.txt", getpid());
    FILE *fp_res = fopen(fn_res, "w");

    char buf[MAX_CMD_STR];
    sprintf(buf, "[srv](%d) child process is created!\n", getpid());
    fwrite(buf, strlen(buf), 1, fp_res);
    sprintf(buf, "[srv](%d) listenfd is closed!\n", getpid());
    fwrite(buf, strlen(buf), 1, fp_res);

    int pin = echo_rep(connfd, fp_res);

    char fn_last[25];
    sprintf(fn_last, "stu_srv_res_%d.txt", pin);
    rename(fn_res, fn_last);

    char wr_in[100];
    sprintf(wr_in, "[srv](%d) res file rename done!\n", getpid());
    fwrite(wr_in, strlen(wr_in), 1, fp_res);
    bzero(wr_in, sizeof(wr_in));
    sprintf(wr_in, "[srv](%d) connfd is closed!\n", getpid());
    fwrite(wr_in, strlen(wr_in), 1, fp_res);
    bzero(wr_in, sizeof(wr_in));
    sprintf(wr_in, "[srv](%d) child process is going to exit!\n", getpid());
    fwrite(wr_in, strlen(wr_in), 1, fp_res);

    close(connfd);
    fclose(fp_res);
    printf("[srv](%d) stu_srv_res_%d.txt is closed\n", getpid(), getpid());
}

void handld_rqt(int sockfd)
{
    struct sockaddr_in from;
    char buf[MAX_CMD_STR];
    while (!sig_to_exit)
    {
        bzero(&from, sizeof(from));
        socklen_t len = sizeof(from);
        int connfd = accept(sockfd, (struct sockaddr *)&from, &len);
        if (connfd == -1 && errno == EINTR && sig_type == SIGINT)
        {
            close(connfd);
            close(sockfd);
            break;
        }
        if (connfd < 0)
            continue;

        pid_t pid = fork();
        if (pid == 0)
        {
            close(sockfd);
            new_chld(connfd);
            exit(0);
        }
        close(connfd);
        FILE *fd = fopen("stu_srv_res_p.txt", "a");
        char inet[55];
        bzero(buf, sizeof(buf));
        sprintf(buf, "[srv](%d) client[%s:%d] is accepted!\n",
                getpid(), inet_ntop(AF_INET, &from.sin_addr.s_addr, inet, sizeof(from)), ntohs(from.sin_port));
        fwrite(buf, strlen(buf), 1, fd);
        fclose(fd);
    }
}

int main(int argc, char *argv[])
{
    struct sigaction act;
    bzero(&act, sizeof(act));
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_flags |= SA_RESTART;
    act.sa_handler = &sig_chld;
    sigaction(SIGCHLD, &act, NULL);

    struct sigaction sigact_pipe, old_sigact_pipe;
    memset(&sigact_pipe, 0, sizeof(sigact_pipe));
    memset(&old_sigact_pipe, 0, sizeof(old_sigact_pipe));
    sigact_pipe.sa_handler = &sig_pipe;
    sigemptyset(&sigact_pipe.sa_mask);
    sigemptyset(&old_sigact_pipe.sa_mask);
    sigact_pipe.sa_flags = 0;
    sigact_pipe.sa_flags |= SA_RESTART;
    sigaction(SIGPIPE, &sigact_pipe, &old_sigact_pipe);

    struct sigaction sg_int;
    bzero(&sg_int, sizeof(sg_int));
    sigemptyset(&sg_int.sa_mask);
    sg_int.sa_flags = 0;
    sg_int.sa_handler = &sig_int;
    sigaction(SIGINT, &sg_int, NULL);

    FILE *fd = fopen("stu_srv_res_p.txt", "w");
    printf("[srv](%d) stu_srv_res_p.txt is opened!\n", getpid());

    struct sockaddr_in local;
    bzero(&local, sizeof(local));
    local.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &local.sin_addr.s_addr);
    local.sin_port = htons(atoi(argv[2]));

    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    char buf[MAX_CMD_STR];
    sprintf(buf, "[srv](%d) server[%s:%d] is initializing!\n", getpid(), argv[1], atoi(argv[2]));
    fwrite(buf, strlen(buf), 1, fd);
    bind(connfd, (struct sockaddr *)&local, sizeof(local));
    listen(connfd, 10);
    fclose(fd);

    handld_rqt(connfd);

    fd = fopen("stu_srv_res_p.txt", "a");
    bzero(buf, sizeof(buf));
    sprintf(buf, "[srv](%d) listenfd is closed!\n", getpid());
    fwrite(buf, strlen(buf), 1, fd);
    bzero(buf, sizeof(buf));
    sprintf(buf, "[srv](%d) parent process is going to exit!\n", getpid());
    fwrite(buf, strlen(buf), 1, fd);
    fclose(fd);

    printf("[srv](%d) stu_srv_res_p.txt is closed!\n", getpid());
    exit(0);
    return 0;
}
