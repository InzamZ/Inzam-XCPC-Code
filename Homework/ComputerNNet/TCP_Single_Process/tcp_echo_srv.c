#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>

int sig_to_exit = 0;
int sig_type = 0;

void sig_int(int signo) {
    printf("[srv] SIGINT is coming!\n");
    sig_type = SIGINT;
    sig_to_exit = 1;
}

// SIGPIPE信号处理函数；
void sig_pipe(int signo) {
    sig_type = SIGPIPE;
    printf("[srv] SIGPIPE is coming!\n");
}

// 业务逻辑处理函数；
void echo_rep(int sockfd) {
    int len_h = 0, len_n = 0, res = 0;
    while (!sig_to_exit) {
        res = read(sockfd, &len_n, sizeof(int));
        len_h = ntohl(len_n);
        char buf[len_h + 1];
        
        if (res == 0) {
            break;
        }
        if (res < 0) {
            if (errno == EINTR) {
                if (sig_type == SIGINT)
                    return;
                continue;
            }
            return;
        }

        int n = 0;
        memset(buf, 0, sizeof buf);
        do {
            res = read(sockfd, buf + n, len_h);
            n += res;
        } while (n < len_h && res > 0);
        if (res < 0) {
            if (errno == EINTR) {
                if (sig_type == SIGINT)
                    return;//但凡收到SIGINT，指示服务器结束
                continue;//若是其他信号中断，则重新执行读取
            }
            free(buf);
            return;
        }
        // 本轮数据长度以及数据本身的读取结束：
        // TODO 按题设要求打印接收到的[echo_rqt]信息；
        printf("[echo_rqt] %s\n", buf);

        write(sockfd, &len_n, sizeof(int));
        write(sockfd, buf, len_h);
    }
}
int main(int argc, char *argv[]) {
    struct sigaction sigact_pipe, old_sigact_pipe;
    memset(&sigact_pipe, 0, sizeof(sigact_pipe));
    memset(&old_sigact_pipe, 0, sizeof(old_sigact_pipe));
    sigact_pipe.sa_handler = &sig_pipe;
    sigemptyset(&old_sigact_pipe.sa_mask);
    sigemptyset(&sigact_pipe.sa_mask);
    sigact_pipe.sa_flags = 0;
    sigact_pipe.sa_flags |= SA_RESTART;
    sigaction(SIGPIPE, &sigact_pipe, &old_sigact_pipe);
    struct sigaction sigact_int;
    sigact_int.sa_handler = &sig_int;
    sigemptyset(&sigact_int.sa_mask);
    sigact_int.sa_flags = 0;
    sigaction(SIGINT, &sigact_int, 0);
    struct sockaddr_in srv_addr, cli_addr;
    socklen_t cli_addr_len, srv_addr_len;
    bzero(&srv_addr, sizeof srv_addr);
    int listenfd, connfd, res;
    if (inet_pton(AF_INET, argv[1], &srv_addr.sin_addr) <= 0) {
        printf("[srv] inet_pton error for %s\n", argv[1]);
        exit(1);
    }
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(atoi(argv[2]));
    srv_addr_len = sizeof(srv_addr);
    connfd = socket(AF_INET, SOCK_STREAM, 0);
    listenfd = bind(connfd, (struct sockaddr *)&srv_addr, srv_addr_len);
    printf("[srv] server[%s:%s] is initializing!\n", argv[1], argv[2]);
    if (listenfd < 0) {
        printf("[srv] socket return %d and errno is %d\n", listenfd, errno);
        return -1;
    }
    res = listen(connfd, 1);
    int resconndfd;
    memset(&cli_addr, 0, sizeof cli_addr);
    
    while (!sig_to_exit) {
        // TODO 获取cli_addr长度，执行accept()：connfd = accept(x,x,x);
        cli_addr_len = sizeof(cli_addr);
        resconndfd = accept(connfd, (struct sockaddr *)&cli_addr, &cli_addr_len);
        // 以下代码紧跟accept()，用于判断accpet()是否因SIG_INT信号退出（本案例中只关心SIGINT）；也可以不做此判断，直接执行 connfd<0 时continue，因为此时sig_to_exit已经指明需要退出accept()主循环，两种方式二选一即可。
        if (resconndfd == -1 && errno == EINTR && sig_type == SIGINT) {
            printf("[srv] accept return -1 and errno is EINTR\n");
            close(resconndfd);
            close(connfd);
            printf("[srv] listenfd is closed!\n");
            break;
        }
        // 若上述if判断不成立且connfd<0，则重启accept();
        if (resconndfd < 0)
            continue;
        // TODO 按题设要求打印客户端端地址client[ip:port]，推荐使用inet_ntop();
        char ip_buf[110];
        inet_ntop(AF_INET, &cli_addr.sin_addr, ip_buf, sizeof cli_addr);
        printf("[srv] client[%s:%d] is accepted!\n", ip_buf, ntohs(cli_addr.sin_port));
        // TODO 执行业务处理函数echo_rep()，进入业务处理循环;
        echo_rep(resconndfd);
        close(resconndfd);
        // TODO 业务函数退出，关闭connfd;
        printf("[srv] connfd is closed!\n");
    }
    printf("[srv] server is going to exit\n");
    return 0;
}