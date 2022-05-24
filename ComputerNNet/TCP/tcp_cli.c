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

// 业务逻辑处理函数
int echo_rqt(int sockfd) {
    char buf[MAX_CMD_STR + 1];
    // 从stdin读取1行
    while (fgets(buf, MAX_CMD_STR, stdin)) {
        // TODO 收到exit，退出循环返回
        if (strncmp(buf, "exit", 4) == 0) {
            break;
        }
        // TODO 查询所读取1行字符的长度，并将行末'\n'更换为'\0'
        int len_h = strlen(buf),len_n = htonl(len_h);
        if (buf[len_h - 1] == '\n') {
            buf[len_h - 1] = '\0';
        }
        // TODO 根据读写边界定义，先发数据长度，再发缓存数据
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
        n = read(sockfd, rsp, len_h);
        if (n < 0) {
            perror("read");
            return -1;
        }
        while (n < len_h) {
            n += read(sockfd, rsp + n, len_h - n);
        }
        rsp[len_h] = '\0';
        printf("[echo_rep] %s\n", rsp);
        /* int型长度变量在读写时请特别注意字节序转换！强烈建议做如下定义，以示区分：*/
        // int len_h = 0; // 按主机字节序读写的长度变量；
        // int len_n = 0; // 按网络字节序读写的长度变量；
        /* 在通过read()读取数据时，有可能因为网络传输等问题，使得read()期望读取长度为LEN的数据，但是首次读取仅返回了长度为RES(RES < LEN)的数据（剩余数据尚未接收至系统内核缓存）。因此在read()后必须进行合理判断、循环读取，直至多次read()返回的RES累加和等于LEN，否则读取数据不完整。测试平台刻意制造了必须多次读取的场景，故要求客户端、服务器都必须执行*/

    }
    return 0;
}

int main(int argc, char *argv[]) {
    // TODO 定义服务器Socket地址srv_addr；
    int connfd, numbytes, res;
    char buf[MAX_CMD_STR + 1];
    struct sockaddr_in srv_addr;
    // TODO 定义Socket连接描述符connfd；
    // 基于argc简单判断命令行指令输入是否正确；
    if (argc != 3) {
        printf("Usage:%s <IP> <PORT>\n", argv[0]);
        return 0;
    }
    // TODO 初始化服务器Socket地址srv_addr，其中会用到argv[1]、argv[2]
    bzero(&srv_addr, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    /* IP地址转换推荐使用inet_pton()；端口地址转换推荐使用atoi(); */
    if (inet_pton(AF_INET, argv[1], &srv_addr.sin_addr) <= 0) {
        perror("inet_pton error for ip");
        exit(1);
    }
    srv_addr.sin_port = atoi(argv[2]);
    // TODO 获取Socket连接描述符: connfd = socket(x,x,x);
    connfd = socket(AF_INET, SOCK_STREAM, 0);
    // TODO 连接服务器，结果存于res: int res = connect(x,x,x);
    res = connect(connfd, (struct sockaddr *) &srv_addr, sizeof(srv_addr));
    // 以下代码紧跟connnect()；
    if (res == -1) {
        perror("Connect failed");
        exit(1);
    }
    if ((numbytes = recv(connfd, buf, MAX_CMD_STR, 0)) == -1) {
        perror("recv failed");
        exit(1);
    }
    buf[numbytes] = '\0';
    if (res == 0) {
        // TODO 连接成功，按题设要求打印服务器端地址server[ip:port]
        printf("[cli] server[%s:%s] is connected!\n", argv[1], argv[2]);
        // TODO 执行业务处理函数echo_rqt();
        echo_rqt(connfd);
    }
    else if (res == -1)
        printf("[cli] connect error! errno is %d\n", errno);
    // TODO 关闭connfd
    close(connfd);
    printf("[cli] connfd is closed!\n");
    printf("[cli] client is exiting!\n");
    return 0;
}
