/*
    TCP ECHO单进程客户端参考模版
    ©2021 张翔 电子科技大学信息与软件工程学院
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_CMD_STR 100
char buf[MAX_CMD_STR + 1];

// 业务逻辑处理函数
int echo_rqt(int sockfd) {
    // 从stdin读取1行
    char *res = fgets(buf, MAX_CMD_STR, stdin);
    while (res) {
        // TODO 收到exit，退出循环返回
        if (strncmp(buf, "exit", 4) == 0)
            return 0;
        int len_h = strnlen(buf, MAX_CMD_STR), len_n = 0;
        buf[len_h - 1] = '\0';
        len_n = htonl(len_h);
        int n = write(sockfd, &len_n, sizeof(int));
        if (n < 0) {
            perror("write");
            return -1;
        }
        n = write(sockfd, buf, len_h);
        // TODO 读取服务器echo回显数据，并打印输出到stdout，依然是先读长度，再根据长度读取数据。
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
        printf("[echo_rep] %s\n", rsp);
        res = fgets(buf, MAX_CMD_STR, stdin);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    // TODO 定义服务器Socket地址srv_addr；
    int connfd, numbytes, res;
    char buf[MAX_CMD_STR + 1];
    struct sockaddr_in srv_addr;
    
    bzero(&srv_addr, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(atoi(argv[2]));

    inet_pton(AF_INET, argv[1], &srv_addr.sin_addr.s_addr);
    connfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(connfd, (struct sockaddr *) &srv_addr, sizeof(srv_addr));
    printf("[cli] server[%s:%s] is connected!\n", argv[1], argv[2]);
    echo_rqt(connfd);
    close(connfd);
    printf("[cli] connfd is closed!\n");
    printf("[cli] client is going to exit!\n");
    return 0;
}
