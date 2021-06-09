#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> >e[110];
int dp[110][110], cnt[110][110][110], imap[110][110];
int n, m, a, b;

#define reg register

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
inline int getcnt(int i, int j, int k)
{
    if (cnt[i][j][k] != -1)
        return cnt[i][j][k] * cnt[i][j][k];
    cnt[i][j][k] = 0;
    for (register int x = 1; x <= n; x++) {
        int y = imap[x][k];
        if (i <= e[x][y].first && e[x][y].second <= j)
            ++cnt[i][j][k];
    }
    return cnt[i][j][k] * cnt[i][j][k];
}

int main()
{
    n = _read(); m = _read();
    for (int i = 1; i <= n; ++i) {
        int k;
        k = _read();
        for (int j = 0; j < k; ++j) {
            a = _read(); b = _read();
            pair<int, int>temp(a, b);
            for (int k = a; k <= b; ++k)
                imap[i][k] = j;
            e[i].push_back(temp);
        }
    }
    for (register int i = 0; i <= m; ++i)
        for (register int j = 0; j <= m; ++j)
            for (register int k = 0; k <= m; ++k)
                cnt[i][j][k] = -1;
    for (register int k = 1; k <= m; ++k)
        for (register int i = 1, j = i + k - 1; j <= m; ++i, ++j) {
            for (register int l = i; l <= j; ++l) {
                int temp = getcnt(i, j, l);
                dp[i][j] = max(dp[i][j], dp[i][l - 1] + temp + dp[l + 1][j]);
            }
        }
    printf("%d\n", dp[1][m]);
    return 0;
}