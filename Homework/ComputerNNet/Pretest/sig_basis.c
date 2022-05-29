#include <stdio.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>

struct sigaction act;

void handler(int signo) {
    if (signo == SIGUSR1)
        printf("[pid](%d) [sig](SIGUSR1) is captured\n", getpid());
    else if (signo == SIGUSR2)
        printf("[pid](%d) [sig](SIGUSR2) is captured\n", getpid());
    else if (signo == SIGINT) {
        printf("[pid](%d) [sig](SIGINT) is captured\n", getpid());
        printf("[pid](%d): exit\n", getpid());
        exit(0);
    }
}

int main(int argv, char *args[]) {
    printf("[pid](%d): start\n", getpid());
    memset(&act, 0, sizeof(act));
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler = handler;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    sigaction(SIGINT, &act, NULL);
    while (1)
        pause();
    return 0;
}