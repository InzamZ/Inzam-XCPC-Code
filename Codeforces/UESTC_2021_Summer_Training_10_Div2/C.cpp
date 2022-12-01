#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IFOR(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define IFor(a,b,c) for(int (a)=(b);(a)<(c);++(a))
#define DFOR(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define DFor(a,b,c) for(int (a)=(b);(a)>(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
vector<int>e[maxn];

ll val[maxn], cnt[maxn], mx[maxn];

void dfs(int rt)
{
    // cout << e[rt].size() << endl;
    IFOR(i, 0, e[rt].size() - 1) {
        dfs(e[rt][i]);
        mx[rt] = max(mx[rt], mx[e[rt][i]]);
        cnt[rt] += cnt[e[rt][i]];
        val[rt] += val[e[rt][i]];
    }
    if (e[rt].size() == 0) {
        cnt[rt] = 1;
        mx[rt] = val[rt];
        return ;
    }
    mx[rt] = max(mx[rt], (ll)ceil(1.0 * val[rt] / cnt[rt]));
}

int main()
{
    int T = 1, n, ans = 0, a;
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        IFOR(i, 2, n) {
            scanf("%d", &a);
            e[a].push_back(i);
        }
        IFOR(i, 1, n) {
            scanf("%lld", &val[i]);
        }
        dfs(1);
        printf("%lld\n", mx[1]);
    }
    return 0;
}