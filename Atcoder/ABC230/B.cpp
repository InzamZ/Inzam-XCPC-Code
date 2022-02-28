//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 1e6 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

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

char s[maxn], t[maxn];

int main()
{
    int T = 1, n, ans = 0;
    // T=_read();
    for (int i = 0; i < 100000; ++i) {
        t[i * 3] = 'o';
        t[i * 3 + 1] = t[i * 3 + 2] = 'x';
    }
    while (T--) {
        ans = 0;
        bool flag = false;
        scanf("%s", s);
        int len = strlen(s);
        if (s[0] == 'o') {
            for (int i = 0; i < len; ++i) {
                if (s[i] != t[i])
                    break;
                else if (i == len - 1)
                    flag = true;
            }
        }
        else if (s[0] == 'x') {
            for (int i = 0; i < len; ++i) {
                if (s[i] != t[i + 1])
                    break;
                else if (i == len - 1)
                    flag = true;
            }
            for (int i = 0; i < len; ++i) {
                if (s[i] != t[i + 2])
                    break;
                else if (i == len - 1)
                    flag = true;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}