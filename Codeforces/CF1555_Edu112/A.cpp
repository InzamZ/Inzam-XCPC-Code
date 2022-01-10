//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
//#define FREAD 1

const int maxn = 2e5 + 10;
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

char s[10][maxn];
char tmp[10][4];

int cnt[10][maxn];

int main()
{
    int T = 1;
    int m, n;
    // scanf("%d", &T);
    tmp[1][0] = 'c'; tmp[1][1] = 'b'; tmp[1][2] = 'a';
    tmp[2][0] = 'a'; tmp[2][1] = 'c'; tmp[2][2] = 'b';
    tmp[3][0] = 'b'; tmp[3][1] = 'a'; tmp[3][2] = 'c';
    tmp[4][0] = 'c'; tmp[4][1] = 'a'; tmp[4][2] = 'b';
    tmp[5][0] = 'b'; tmp[5][1] = 'c'; tmp[5][2] = 'a';
    tmp[6][0] = 'a'; tmp[6][1] = 'b'; tmp[6][2] = 'c';
    while (T--) {
        int len;
        scanf("%d %d", &n, &m);
        scanf("%s", s[0]);
        len = strlen(s[0]);
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j <= 6; ++j)
                s[j][i] = tmp[j][i % 3];
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= 6; ++j) {
                cnt[j][i] = cnt[j][i - 1];
                if (s[0][i - 1] != s[j][i - 1])
                    ++cnt[j][i];
            }
        }
        for (int i = 1; i <= m; ++i) {
            int l, r, ans = 1e7;
            scanf("%d %d", &l, &r);
            for (int j = 1; j <= 6; ++j)
                ans = min(ans, cnt[j][r] - cnt[j][l - 1]);
            printf("%d\n", ans);
        }
    }
    return 0;
}