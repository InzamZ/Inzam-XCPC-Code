#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 15;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int imap[maxn][maxn][maxn], t[maxn][maxn];
int T = 1, n, ans, d, r, c;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char s[maxn];

void update(int r, int c, int x) //第x天海胆更新完位置
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            imap[i][j][x] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i == r && j == c) {
                imap[i][j][x] = 0;
                continue;
            }
            int cnt = 0;
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    if ((k || l) && imap[i + k][j + l][x - 1] == 1)
                        ++cnt;
                }
            }
            if (cnt == 3 && imap[i][j][x - 1] == 0)
                imap[i][j][x] = 1;
            else if ((cnt == 3 || cnt == 2) && imap[i][j][x - 1] == 1)
                imap[i][j][x] = 1;
            else
                imap[i][j][x] = 0;
        }
}

void solve(int r, int c, int x)
{
    if (x > d)
        return ;
    if (ans <= d)
        return ;
    if (r <= 0 || r > n || c > n || c <= 0)
        return ;
    update(r, c, x);
    bool flag = true;
    for (int i = 1; flag && i <= n; ++i) {
        for (int j = 1; flag && j <= n; ++j) {
            if (t[i][j] != imap[i][j][x])
                flag = false;
        }
    }
    if (flag) {
        ans = min(x, ans);
        return ;
    }
    else {
        for (int i = 0; i < 4; ++i) {
            solve(r + dir[i][0], c + dir[i][1], x + 1);
            if (ans <= d)
                return ;
        }
    }
}

int main()
{
    // scanf("%d",&T);
    while (T--) {
        ans = 0;
        scanf("%d %d %d %d", &n, &d, &r, &c);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s);
            for (int j = 0; j < n; ++j) {
                if (s[j] == '1')
                    imap[i][j + 1][0] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s);
            for (int j = 0; j < n; ++j) {
                if (s[j] == '1')
                    t[i][j + 1] = 1;
            }
        }
        ans = d + 1;
        ++r; ++c;
        if (d == 0) {
            bool flag = true;
            for (int i = 1; flag && i <= n; ++i) {
                for (int j = 1; flag && j <= n; ++j) {
                    if (t[i][j] != imap[i][j][0])
                        flag = false;
                }
            }
            if (flag)
                ans = 0;
        }
        else {
            for (int i = 0; i < 4; ++i)
                solve(r + dir[i][0], c + dir[i][1], 1);
        }
        printf("%s\n", ans == d + 1 ? "NO" : "YES");
    }
    return 0;
}