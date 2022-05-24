#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

char str1[50] = "Child process 1 is sending a message!";
char str2[50] = "Child process 2 is sending a message!";

int main() {
    int fd[2];
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }
    pid_t pid1 = fork();
    if (pid1 == 0) {
        printf("This is child1 [pid]%d\n", getpid());
        close(fd[0]);
        write(fd[1], str1, sizeof(str1));
        exit(0);
    }
    else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            printf("This is child2 [pid]%d\n", getpid());
            close(fd[0]);
            write(fd[1], str2, sizeof(str2));
            exit(0);
        }
        else{

            
            sleep(1);
            printf("This is parent [pid]%d\n", getpid());
            close(fd[1]);
            char buf[50];
            read(fd[0], buf, sizeof(buf));
            printf("%s\n", buf);
            read(fd[0], buf, sizeof(buf));
            printf("%s\n", buf);
        }
    }
    return 0;
}