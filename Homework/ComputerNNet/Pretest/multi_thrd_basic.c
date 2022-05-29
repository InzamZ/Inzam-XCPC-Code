#include <stdio.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>

pthread_t tid[10];
pthread_attr_t attr;

char buf[10][50];

void *run(void *argv) {
    char *buff = (char *)argv;
    if (buff != buf[0])
        pthread_detach(pthread_self());
    printf("[spid](%d) [read](%s)\n", syscall(SYS_gettid), buff);
    printf("[spid](%ld) [tgid](%d): [ptid](%lu) start\n", syscall(SYS_gettid), getpid(), pthread_self());
    printf("[spid](%ld) [tgid](%d): [ptid](%lu) [func](pthread_exit)\n", syscall(SYS_gettid), getpid(), pthread_self());
    pthread_exit(NULL);
}

int main(int argv, char *argc[]) {
    int conc_amnt = atoi(argc[2]);
    printf("[spid](%d) [tgid](%lu): [ptid](%lu) start\n", syscall(SYS_gettid), getpid(), pthread_self());
    FILE *td = fopen("./td.txt", "r");
    for (int i = 1; i < conc_amnt; ++i) {
        fgets(buf[i - 1], 50, td);
        buf[i - 1][strlen(buf[i - 1]) - 1] = '\0';
        printf("[spid](%d) [read](%s)\n", syscall(SYS_gettid), buf[i - 1]);
        if (i == 1) {
            pthread_attr_init(&attr);
            pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
            pthread_create(&tid[i], &attr, (void *)&run, (void *)buf[i - 1]);
            pthread_attr_destroy(&attr);
        }
        else
            pthread_create(&tid[i], NULL, (void *)&run, (void *)buf[i - 1]);
    }
    fclose(td);
    sleep(1);
    printf("[spid](%d) [tgid](%lu): [ptid](%lu) [func](exit)\n", getpid(), syscall(SYS_gettid), pthread_self());
    exit(0);
    return 0;
}