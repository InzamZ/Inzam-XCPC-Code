//InzamZ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "dirent.h"
#include <sys/stat.h>
#include <sys/types.h>

int scanDir(char *path, char *filePath) {
    DIR *dir;
    struct dirent *ptr;
    char base[1000];
    if ((dir = opendir(path)) == NULL) {
        perror("Open dir error...");
        exit(1);
    }
    while ((ptr = readdir(dir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;
        else if (ptr->d_type == 8) {
            FILE *fp;
            char dirr[1000];
            strcpy(dirr, path);
            strcat(dirr, "/");
            strcat(dirr, ptr->d_name);
            fp = fopen(dirr, "r");
            if (fp == NULL) {
                perror("Open file error...");
                exit(1);
            }
            char ch[100];
            while (fgets(ch, 100, fp) != NULL) {
                if (strcmp(ch, "114514") != 0) {
                    printf("%s", ch);
                    printf("%s", dirr);
                    exit(1);
                }
            }
        }
        else if (ptr->d_type == 4) {
            // dir
            strcpy(base, path);
            strcat(base, "/");
            strcat(base, ptr->d_name);
            scanDir(base, filePath);
        }
    }
    closedir(dir);
    return 0;
}

signed main() {
    DIR *dir;
    struct dirent *ptr;
    char base_path[100] = "/home/user/桌面/风行迷踪";
    //遍历目录，输出文件内容不等于 “114514” 的文件
    scanDir(base_path, base_path);
    return 0;
}
