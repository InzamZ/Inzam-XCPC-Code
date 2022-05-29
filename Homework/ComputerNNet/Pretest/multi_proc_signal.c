#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
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

int conc_amnt;

void pa_handle_sigchld(int signo) {
    if (signo == SIGINT) {
        printf("[pid](%d): [sig](SIGINT) is handled in pa_handle_sigint()\n", getpid());
        printf("[pid](%d): [func](exit) with [conc_amnt](%d)\n", getpid(), conc_amnt);
        exit(0);
    }
    if (signo == SIGCHLD) {
        int pid,status;
        while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
            printf("[pid](%d): [cpid](%d) is waited in pa_handle_sigchld()\n", getpid(), pid);
            --conc_amnt;
        }
    }
}

int main(int argc, char *argv[]) {
    struct sigaction act;
    pid_t pidl[10];
    conc_amnt = atoi(argv[2]);
    int n = conc_amnt;
    printf("[pid](%d): start\n", getpid());
    memset(&act, 0, sizeof(act));
    sigemptyset(&act.sa_mask);
    act.sa_handler = pa_handle_sigchld;
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGCHLD, &act, NULL);
    pid_t pid;
    for (int i = 1; i < n; i++) {
        pid = fork();
        if (pid == 0) {
            printf("[pid](%d): start\n", getpid());
            // printf("[pid](%d): [func](exit) with [conc_amnt](%d)\n", getpid(), conc_amnt);
            while (1)
                pause();
        }
        else
            pidl[i] = pid;
    }
    sleep(1);
    for (int i = 1; i < n; i++) {
        kill(pidl[i], SIGINT);
        // printf("[pid](%d): [conc_amnt](%d) [cpid](%d) is signaled\n", getpid(), conc_amnt, pidl[i]);
    }
    while (conc_amnt > 1) {
        printf("[pid](%d): [func](pause) with [conc_amnt](%d)\n", getpid(), conc_amnt);
        pause();
    }
    while (1)
        pause();
    return 0;
}