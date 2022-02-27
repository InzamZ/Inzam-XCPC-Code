//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 50;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;
char s[maxb];

#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

int main()
{
    int T = 1, n, ans = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 3)
            printf("3 2 1\n1 3 2\n3 1 2\n");
        else {
            printf("1 3 2");
            for (int i = 4; i <= n; ++i)
                printf(" %d", i);
            putchar('\n');
            for (int i = n, j = 0; i >= 1; --i)
                s[i] = ++j;
            for (int i = 1; i < n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (j == i)
                        printf("%d", s[j + 1]);
                    else if (j == i + 1)
                        printf("%d", s[j - 1]);
                    else
                        printf("%d", s[j]);
                    if (j == n)
                        putchar('\n');
                    else
                        putchar(' ');
                }
            }
        }
    }
    return 0;
}