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

#define bprintf(fp,format, ...)\
    if(fp==NULL){printf(format, ##__VA_ARGS__);}\
    else{printf(format,##__VA_ARGS__);\
        fprintf(fp,format,##__VA_ARGS__);fflush(fp);}

void sig_int(int signo) {
    FILE *fp = fopen("stu_srv_res_p.txt", "a");
    bprintf(fp, "[srv](%d) SIGINT is coming!\n", getpid());
    fclose(fp);

    sig_type = SIGINT;
    sig_to_exit = 1;
}

// SIGPIPE信号处理函数；
void sig_pipe(int signo) {
    sig_type = SIGPIPE;
    bprintf(NULL,"[srv](%d) SIGPIPE is coming!\n", getpid());
}

void sig_chld(int signo)
{
    sig_type = SIGCHLD;
    int pid, sta;
    FILE *fp = fopen("stu_srv_res_p.txt", "a");
    while ((pid = waitpid(-1, &sta, WNOHANG)) > 0)
    {
        bprintf(fp, "[srv](%d) SIGCHLD is coming!\n", getpid());
        bprintf(NULL,"[srv](%d) server child(%d) terminated.\n", getpid(), pid);
    }
    fclose(fp);
}

// 业务逻辑处理函数；
int echo_rep(int sockfd, FILE *fp) {

    int pin;
    int len_h = 0, len_n = 0, res = 0;

    while (!sig_to_exit) {

        res = read(sockfd, &pin, sizeof(int));

        if (res == 0) {
            break;
        }
        if (res < 0) {
            if (errno == EINTR) {
                if (sig_type == SIGINT)
                    break;
                continue;
            }
            return 0;
        }
        res = read(sockfd, &len_n, sizeof(int));
        len_h = ntohl(len_n);
        char buf[len_h + 1]; 
        memset(buf, 0, sizeof buf);

        int n = 0;
        do {
            res = read(sockfd, buf + n, len_h);
            n += res;
        } while (n + 1 < len_h && res > 0);
        if (res < 0) {
            if (errno == EINTR) {
                if (sig_type == SIGINT)
                    break;//但凡收到SIGINT，指示服务器结束
                continue;//若是其他信号中断，则重新执行读取
            }
            free(buf);
            return 0;
        }

        bprintf(fp, "[echo_rqt](%d) %s\n", getpid(), buf);

        write(sockfd, &pin, sizeof(pin));
        write(sockfd, &len_n, sizeof(int));
        write(sockfd, buf, len_h);
    }
    pin = ntohl(pin);
    return pin;
}

void new_chd_pro(int connfd)
{
    char filename[50], new_filename[50];
    memset(filename,0,sizeof filename);
    memset(new_filename,0,sizeof new_filename);
    sprintf(filename, "stu_srv_res_%d.txt", getpid());

    FILE *fp = fopen(filename, "w");
    bprintf(fp, "[srv](%d) child process is created!\n", getpid());
    bprintf(fp, "[srv](%d) listenfd is closed!\n", getpid());

    int pin = echo_rep(connfd, fp);
    sprintf(new_filename, "stu_srv_res_%d.txt", pin);
    rename(filename, new_filename);

    bprintf(fp, "[srv](%d) res file rename done!\n", getpid());
    bprintf(fp, "[srv](%d) connfd is closed!\n", getpid());
    bprintf(fp, "[srv](%d) child process is going to exit!\n", getpid());

    close(connfd);
    fclose(fp);
    bprintf(NULL,"[srv](%d) stu_srv_res_%d.txt is closed\n", getpid(), getpid())
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


    struct sigaction act;
    bzero(&act, sizeof(act));
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_flags |= SA_RESTART;
    act.sa_handler = &sig_chld;
    sigaction(SIGCHLD, &act, NULL);

    FILE *fp = fopen("stu_srv_res_p.txt", "w");
    bprintf(NULL,"[srv](%d) stu_srv_res_p.txt is opened!\n", getpid());

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
    bprintf(fp, "[srv](%d) server[%s:%s] is initializing!\n", getpid(), argv[1], argv[2]);
    if (listenfd < 0) {
        printf("[srv] socket return %d and errno is %d\n", listenfd, errno);
        return -1;
    }

    res = listen(connfd, 10);
    int resconndfd;
    fclose(fp);

    memset(&cli_addr, 0, sizeof cli_addr);
    while (!sig_to_exit) {
        cli_addr_len = sizeof(cli_addr);
        resconndfd = accept(connfd, (struct sockaddr *)&cli_addr, &cli_addr_len);
        // 以下代码紧跟accept()，用于判断accpet()是否因SIG_INT信号退出（本案例中只关心SIGINT）；也可以不做此判断，直接执行 connfd<0 时continue，因为此时sig_to_exit已经指明需要退出accept()主循环，两种方式二选一即可。
        if (resconndfd == -1 && errno == EINTR && sig_type == SIGINT) {
            close(resconndfd);
            close(connfd);
            break;
        }
        // 若上述if判断不成立且connfd<0，则重启accept();
        if (resconndfd < 0)
            continue;

        pid_t pid = fork();
        if (!pid) 
        {
            close(connfd);
            new_chd_pro(resconndfd);
            exit(0);
        }
        close(resconndfd);
        FILE *fp = fopen("stu_srv_res_p.txt", "a");
        char ip_buf[110];
        memset(ip_buf,0,sizeof ip_buf);
        bprintf(fp, "[srv](%d) client[%s:%d] is accepted!\n",
            getpid(), inet_ntop(AF_INET, &cli_addr.sin_addr.s_addr, ip_buf, sizeof(cli_addr)), ntohs(cli_addr.sin_port));
        fclose(fp);
    }
    
    fp = fopen("stu_srv_res_p.txt", "a");
    bprintf(fp, "[srv](%d) listenfd is closed!\n", getpid());
    bprintf(fp, "[srv](%d) parent process is going to exit!\n", getpid());
    fclose(fp);
    bprintf(NULL,"[srv](%d) stu_srv_res_p.txt is closed!\n", getpid());
    
    return 0;
}