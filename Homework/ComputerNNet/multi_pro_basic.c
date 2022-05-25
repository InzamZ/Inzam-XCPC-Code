#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[2]);
    printf("[pid](%d) [ppid](%d): start\n", getpid(), getppid());
    int fd1_td1 = open("./td1.txt", O_RDONLY);
    printf("[pid](%d) [ppid](%d): [fd1_td1](%d) is got\n", getpid(), getppid(), fd1_td1);
    for (int i = 1; i < n; ++i) {
        int fid = fork();
        if (fid == 0) {
            printf("[pid](%d) [ppid](%d): start\n", getpid(), getppid());
            char s[6];
            read(fd1_td1, s, 5);
            printf("[pid](%d) [ppid](%d): [read](%s) by [fd1_td1](%d)\n", getpid(), getppid(), s, fd1_td1);
            int fd2_td1 = open("./td1.txt", O_RDONLY);
            printf("[pid](%d) [ppid](%d): [fd2_td1](%d) is got\n", getpid(), getppid(), fd2_td1);
            read(fd2_td1, s, 5);
            printf("[pid](%d) [ppid](%d): [read](%s) by [fd2_td1](%d)\n", getpid(), getppid(), s, fd2_td1);
            close(fd2_td1);
            close(fd1_td1);
            printf("[pid](%d) [ppid](%d): exit\n", getpid(), getppid());
            exit(0);
        }
    }
    char s[6];
    read(fd1_td1, s, 5);
    printf("[pid](%d) [ppid](%d): [read](%s) by [fd1_td1](%d)\n", getpid(), getppid(), s, fd1_td1);
    close(fd1_td1);
    int fd1_td2 = open("./td2.txt", O_RDONLY);
    printf("[pid](%d) [ppid](%d): [fd1_td2](%d) is got\n", getpid(), getppid(), fd1_td2);
    read(fd1_td2, s, 5);
    printf("[pid](%d) [ppid](%d): [read](%s) by [fd1_td2](%d)\n", getpid(), getppid(), s, fd1_td2);
    close(fd1_td2);
    sleep(2);
    printf("[pid](%d) [ppid](%d): exit\n", getpid(), getppid());
    return 0;
}