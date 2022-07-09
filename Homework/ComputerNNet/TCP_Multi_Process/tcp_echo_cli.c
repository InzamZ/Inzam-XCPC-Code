#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_CMD_STR 100
char buf[MAX_CMD_STR + 1];
int cnt = 1;
char *argcpy[5];

#define bprintf(fp,format, ...)\
    if(fp==NULL){printf(format, ##__VA_ARGS__);}\
    else{printf(format,##__VA_ARGS__);\
        fprintf(fp,format,##__VA_ARGS__);fflush(fp);}

void sig_chld(int signo) {
    int pid, status;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
        cnt++;
}

int echo_rqt(int sockfd, FILE *fp_wr, int pin_h) {
    char filename[MAX_CMD_STR];
    sprintf(filename, "td%d.txt", pin_h);
    FILE *fp = fopen(filename, "r");
    int pin_n = htonl(pin_h);
    char *res = fgets(buf, MAX_CMD_STR, fp);
    while (res) {
        if (strncmp(buf, "exit", 4) == 0)
            break;
        int len_h = strnlen(buf, MAX_CMD_STR), len_n = 0;
        buf[len_h - 1] = '\0';
        len_n = htonl(len_h);
        write(sockfd, &pin_n, sizeof(int));
        int n = write(sockfd, &len_n, sizeof(int));
        // if (n < 0) {
        //     perror("write");
        //     return -1;
        // }
        n = write(sockfd, buf, len_h);

        read(sockfd, &len_n, sizeof(int));
        // pin_h = ntohl(pin_n);
        n = read(sockfd, &len_n, sizeof(int));
        len_h = ntohl(len_n);
        if (n < 0) {
            perror("read");
            return -1;
        }
        char rsp[len_h + 1];
        n = 0;
        do {
            read(sockfd, rsp + n, len_h);
            n = strnlen(rsp, MAX_CMD_STR);
        }
        while (n + 1 < len_h);
        bprintf(fp_wr, "[echo_rep](%d) %s\n", getpid(), buf);
        res = fgets(buf, MAX_CMD_STR, fp);
    }
    close(sockfd);
    bprintf(fp_wr, "[cli](%d) connfd is closed!\n", getpid());
    if (pin_h == 0){
        bprintf(fp_wr, "[cli](%d) parent process is going to exit!\n", getpid());
    }
    else{
        bprintf(fp_wr, "[cli](%d) child process is going to exit!\n", getpid());
    }
    bprintf(NULL, "[cli](%d) stu_cli_res_%d.txt is closed!\n", getpid(), pin_h);
    fclose(fp_wr);
    fclose(fp);
    return 0;
}

void solve(int pin, int max_proc) {
    pid_t pid = fork();
    if (pid == 0) {
        char res[MAX_CMD_STR];
        sprintf(res, "stu_cli_res_%d.txt", pin);
        FILE *fp = fopen(res, "w");
        bprintf(0,"[cli](%d) %s is created!\n", getpid(), res);
        bprintf(fp, "[cli](%d) child process %d is created!\n", getpid(), pin);

        struct sockaddr_in srv_addr;
        memset(&srv_addr, 0, sizeof srv_addr);
        inet_pton(AF_INET, argcpy[1], &srv_addr.sin_addr.s_addr);
        srv_addr.sin_port = htons(atoi(argcpy[2]));
        srv_addr.sin_family = AF_INET;
        int connfd = socket(AF_INET, SOCK_STREAM, 0);
        connect(connfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
        memset(res, 0, sizeof(res));
        inet_ntop(AF_INET, &srv_addr.sin_addr, res, sizeof(srv_addr));
        bprintf(fp, "[cli](%d) server[%s:%s] is connected!\n", getpid(), res, argcpy[2]);
        echo_rqt(connfd, fp, pin);
        close(connfd);
        exit(0);
    }
    else {
        if (pin + 1 != max_proc)
            solve(pin + 1, max_proc);
        else {
            pin = 0;
            char res[MAX_CMD_STR];
            memset(res, 0, sizeof(res));
            sprintf(res, "stu_cli_res_%d.txt", pin);
            FILE *fp = fopen(res, "w");
            bprintf(NULL,"[cli](%d) %s is created!\n", getpid(), res);
            struct sockaddr_in srv_addr;
            memset(&srv_addr, 0, sizeof(srv_addr));
            srv_addr.sin_family = AF_INET;
            inet_pton(AF_INET, argcpy[1], &srv_addr.sin_addr.s_addr);
            srv_addr.sin_port = htons(atoi(argcpy[2]));
            int connfd = socket(AF_INET, SOCK_STREAM, 0);
            connect(connfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
            memset(res, 0, sizeof(res));
            inet_ntop(AF_INET, &srv_addr.sin_addr, res, sizeof(srv_addr));
            bprintf(fp, "[cli](%d) server[%s:%d] is connected!\n", getpid(), res, ntohs(srv_addr.sin_port));
            echo_rqt(connfd, fp, pin);
            while (cnt < max_proc)
                pause();
            close(connfd);
            exit(0);
        }
    }
}

int main(int argc, char *argv[]) {
    
    struct sigaction act;
    bzero(&act, sizeof(act));
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_flags |= SA_RESTART;
    act.sa_handler = &sig_chld;
    sigaction(SIGCHLD, &act, NULL);
    int connfd, numbytes, res;
    char buf[MAX_CMD_STR + 1];
    argcpy[1] = argv[1];
    argcpy[2] = argv[2];
    argcpy[3] = argv[3];
    int max_proc = atoi(argv[3]);
    int pin = 0;

    solve(1, max_proc);
    return 0;
}
