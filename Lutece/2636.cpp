#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char tx[1000010], str[1000010];
int f[1000010], cnt = 0;

void kmp(char tx[], char str[])
{
    int i = -1, j = -1;
    int m = strlen(tx), n = strlen(str);
    while (i < m) {
        if (j == -1 || tx[i] == str[j]) {
            i++; j++;
        }
        else
            j = f[j];
        if (j == n) {
            ++cnt;
            j = f[j];
        }
    }
}

int main()
{
    scanf ("%s", tx);
    scanf ("%s", str);
    int m = strlen(tx), n = strlen(str);
    f[0] = -1;
    f[1] = -1;
    int j = -1, i = 0;
//kmp中的核心数组next
    while (i < n) {
        if (j == -1 || str[i] == str[j]) {
            i++; j++; f[i] = j;
        }
        else
            j = f[j];
    }
//next 即自己扫自己，得到的最大前缀
    kmp(tx, str);
    printf("%d\n", cnt);
    return 0;
}