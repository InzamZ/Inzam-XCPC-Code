//InzamZ
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int all = 0, t, n;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &n);
        char c;
        bool flag = true, beg = false;
        int i = 0, cut[30];
        memset(cut, 0, sizeof(cut));
        while (i <= n) {
            c = getchar();
            if (c == '\n') {
                i++;
                continue;
            }
            ++cut[c - 'a'];
        }
        for (int j = 0; j <= 25; j++) {
            if (cut[j] % n != 0) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
