#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int cpFile(char *src, char *dest) {
    int fd1, fd2;
    char buf[1024];
    int n;
    fd1 = open(src, O_RDONLY);
    fd2 = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    while ((n = read(fd1, buf, sizeof(buf))) > 0)
        write(fd2, buf, n);
    close(fd1);
    close(fd2);
    return 0;
}

int cpDir(char *src, char *dest) {
    DIR *dir = opendir(src);
    struct dirent *entry;
    struct stat statbuf;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        char *src_path = (char *) malloc(sizeof(char) * (strlen(src) + strlen(entry->d_name) + 2));
        char *dest_path = (char *) malloc(sizeof(char) * (strlen(dest) + strlen(entry->d_name) + 2));
        sprintf(src_path, "%s/%s", src, entry->d_name);
        sprintf(dest_path, "%s/%s", dest, entry->d_name);
        lstat(src_path, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            mkdir(dest_path, statbuf.st_mode);
            cpDir(src_path, dest_path);
        }
        else if (S_ISREG(statbuf.st_mode))
            cpFile(src_path, dest_path);
    }
    return 0;
}

int main(int argv, char *args[]) {
    if (argv != 3) {
        printf("Usage: main.out <src directory> <dest directory>\n");
        return 1;
    }
    char *src = args[1];
    char *dest = args[2];
    cpDir(src, dest);
    return 0;
}