#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e3 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

// inline char nc()
// {
//     static char buf[100000], *p1 = buf, *p2 = buf;
//     return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
// }
// inline int read()
// {
//     char ch = nc(); int sum = 0;
//     while (!(ch >= '0' && ch <= '9'))
//         ch = nc();
//     while (ch >= '0' && ch <= '9')
//         sum = sum * 10 + ch - 48, ch = nc();
//     return sum;
// }

char s[maxn];
int ans = 10;

int dfs(int x, int cnt1, int cnt2)
{
    if (x == 11)
        return 0;
    if (5 - x / 2 + cnt1 < cnt2) {
        ans = min(ans, x - 1);
        return 0;
    }
    if (5 - (x - 1) / 2 + cnt2 < cnt1) {
        ans = min(ans, x - 1);
        return 0;
    }
    if (x % 2 == 1 && s[x - 1] == '?') {
        dfs(x + 1, cnt1 + 1, cnt2);
        dfs(x + 1, cnt1, cnt2);
    }
    if (x % 2 == 0 && s[x - 1] == '?') {
        dfs(x + 1, cnt1, cnt2 + 1);
        dfs(x + 1, cnt1, cnt2);
    }
    if (s[x - 1] == '0')
        dfs(x + 1, cnt1, cnt2);
    if (x % 2 == 1 && s[x - 1] == '1')
        dfs(x + 1, cnt1 + 1, cnt2);
    if (x % 2 == 0 && s[x - 1] == '1')
        dfs(x + 1, cnt1, cnt2 + 1);
    return 0;
}

int main()
{
    int T = 1, n, i;
    scanf("%d", &T);
    while (T--) {
        ans = 10;
        scanf("%s", s);
        dfs(1, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}