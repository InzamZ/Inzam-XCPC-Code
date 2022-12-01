#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
bool flag = false;

int s[maxn];

int T = 1, n, ans = 0, b;
void dfs(int x, int ro)
{
    if (x == n + 1) {
        if (ro % 360 == 0)
            flag = true;
        return ;
    }
    dfs(x + 1, ro - s[x]);
    if (flag)
        return ;
    dfs(x + 1, ro + s[x]);
    if (flag)
        return ;
}

int main()
{
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &s[i]);
        dfs(1, 0);
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}