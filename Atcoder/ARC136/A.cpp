//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

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

char s[maxn];

int main()
{
    int T = 1, n, ans = 0, cnt = 0;
    // T=_read();
    while (T--) {
        scanf("%d ", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%c", &s[cnt]);
            if (s[cnt] == 'A') {
                s[cnt] = s[cnt + 1] = 'B';
                ++cnt;
            }
            ++cnt;
        }
        for (int i = 0; i < cnt; ++i) {
            if (s[i] == 'B' && s[i + 1] == 'B') {
                putchar('A'); ++i;
            }
            else
                putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}