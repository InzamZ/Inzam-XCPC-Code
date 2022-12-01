#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int T = 1, n, ans = 0, l, r, mid, k, a, m;
int s[maxn];

priority_queue<int, vector<int>, greater<int>>q;

bool check(int x)
{
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= x; ++i)
        q.push(s[i]);
    q.push(n + 1);
    int cur = 0, cnt = 0;
    while (!q.empty()) {
        int res = q.top(); q.pop();
        if ((res - cur) < 0)
            continue;
        cnt += ((res - cur) / (a + 1));
        cur = res;
    }
    return cnt >= k;
}

int main()
{
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d %d %d %d", &n, &k, &a, &m);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &s[i]);
        l = 0, r = m + 1;
        if (k * (a + 1) > n + 1)
            l = -1;
        else if (l == r - 1 && check(l))
            l = m;
        else if (l == r - 1 && !check(l))
            l = 0;
        else
            while (l + 1 < r) {
                mid = (l + r) >> 1;
                if (check(mid))
                    l = mid;
                else
                    r = mid;
            }
        printf("%d\n", l == m ? -1 : l + 1);
    }
    return 0;
}