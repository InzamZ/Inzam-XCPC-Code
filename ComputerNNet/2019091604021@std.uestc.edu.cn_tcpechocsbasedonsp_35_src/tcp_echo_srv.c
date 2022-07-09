#include <sys/types.h>
#include <sys/socket.h>
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
#define MAX_CMD_STR 100

int sig_to_exit = 0;
int sig_type = 0;
void sig_pipe(int signo)
{
    sig_type = SIGPIPE;
    printf("[srv] SIGPIPE is coming!\n");
}
void sig_int(int signo)
{
    printf("[srv] SIGINT is coming!\n");
    sig_type = SIGINT;
    sig_to_exit = 1;
}

void echo_rep(int connfd)
{
    int len_n = 0;
    int len_h = 0;
    int res = -1;
    while (!sig_to_exit)
    {
        res = read(connfd, &len_n, sizeof(len_n));
        len_n = ntohl(len_n);

        if (res == 0)
            break;

        if (res < 0)
        {
            if (errno == EINTR)
            {
                if (sig_type == SIGINT)
                    return;
                continue;
            }
            return;
        }
        len_h = 0;
        char buf[len_n + 1];
        memset(buf, 0, sizeof(buf));
        do 
        {
            res = read(connfd , buf+len_h, len_n);
            len_h += res;
        }while (len_h < len_n && res > 0);
        if (res < 0)
        {
            if (errno == EINTR)
            {
                if (sig_type == SIGINT)
                    return;
                continue;
            }
            free(buf);
            return;
        }

        printf("[echo_rqt] %s\n", buf);

        len_h = htonl(len_h);
        write(connfd, &len_h, sizeof(len_h));
        len_h = ntohl(len_h);
        write(connfd, buf, len_h);
    }
}
void handle_rst(int sockfd)
{
    int connfd;
    struct sockaddr_in cli_addr;
    memset(&cli_addr, 0, sizeof(cli_addr));
    socklen_t len = sizeof(cli_addr);

    while (!sig_to_exit)
    {
        connfd = accept(sockfd, (struct sockaddr *)&cli_addr, &len);
        if (connfd == -1 && errno == EINTR && sig_type == SIGINT)
        {
            printf("[srv] accept return -1 and errno is EINTR\n");
            close(connfd);
            close(sockfd);
            printf("[srv] listenfd is closed!\n");
            break;
        }
        if (connfd < 0)
            continue;
        char inet[105];
        inet_ntop(AF_INET, &cli_addr.sin_addr, inet, sizeof(cli_addr));
        printf("[srv] client[%s:%d] is accepted!\n", inet, ntohs(cli_addr.sin_port));

        echo_rep(connfd);
        close(connfd);
        printf("[srv] connfd is closed!\n");
    }
}

int main(int argc, char *argv[])
{
    struct sigaction x, sigact_pipe, old_sigact_pipe;

    memset(&sigact_pipe, 0, sizeof(sigact_pipe));
    memset(&old_sigact_pipe, 0, sizeof(old_sigact_pipe));
    sigact_pipe.sa_handler = &sig_pipe;
    sigemptyset(&sigact_pipe.sa_mask);
    sigemptyset(&old_sigact_pipe.sa_mask);
    sigact_pipe.sa_flags = 0;
    sigact_pipe.sa_flags |= SA_RESTART;
    sigaction(SIGPIPE, &sigact_pipe, &old_sigact_pipe);

    memset(&x, 0, sizeof(x));
    sigemptyset(&x.sa_mask);
    x.sa_flags = 0;
    x.sa_handler = &sig_int;
    sigaction(SIGINT, &x, NULL);

    struct sockaddr_in srv_addr;
    bzero(&srv_addr, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &srv_addr.sin_addr.s_addr);
    srv_addr.sin_port = htons(atoi(argv[2]));

    socklen_t srv_len = sizeof(srv_addr);

    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    int listenfd = bind(connfd, (struct sockaddr *)&srv_addr, srv_len);
    printf("[srv] server[%s:%d] is initializing!\n", argv[1], (atoi(argv[2])));
    listen(connfd, 1);

    handle_rst(connfd);

    
    printf("[srv] server is going to exit!\n");
    exit(0);
    return 0;
}