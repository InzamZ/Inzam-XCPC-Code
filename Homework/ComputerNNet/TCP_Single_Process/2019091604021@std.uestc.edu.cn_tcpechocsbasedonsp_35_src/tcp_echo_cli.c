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

struct sockaddr_in local;

void cli_echo_rqt(int s_s)
{
    char buf[MAX_CMD_STR+1];
    int len_h = 0 ;
    int len_n = 0 ;
    while (fgets(buf, MAX_CMD_STR, stdin))
    {
        if ( strncmp(buf, "exit", 4) == 0 ) return ;
        
        len_h = strnlen(buf, MAX_CMD_STR);
        buf[len_h-1] = '\0';
        
        len_h = htonl(len_h);
        write(s_s, &len_h, sizeof(len_h));
        len_h = ntohl(len_h);
        write(s_s, buf, len_h);
        
        memset(buf, 0, sizeof(buf));

        read(s_s, &len_n, sizeof(len_n));
        len_n = ntohl(len_n);


        len_h = 0;
        do 
        {
            read(s_s, buf+len_h, len_n);
            len_h = strnlen(buf, MAX_CMD_STR);
        }while (len_h + 1 < len_n);


        printf("[echo_rep] %s\n",buf);
    }
    
}

int main (int argc, char *argv[])
{
    bzero(&local, sizeof(local));
    local.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &local.sin_addr.s_addr);
    local.sin_port = htons(atoi(argv[2]));

    
    int s_s = socket(AF_INET, SOCK_STREAM, 0);
    connect(s_s, (struct sockaddr*)&local, sizeof(local));
    printf("[cli] server[%s:%d] is connected!\n",argv[1], (atoi(argv[2])));
    

    cli_echo_rqt(s_s);
    close(s_s);
    printf("[cli] connfd is closed!\n");
    printf("[cli] client is going to exit!\n");
    return 0;
}