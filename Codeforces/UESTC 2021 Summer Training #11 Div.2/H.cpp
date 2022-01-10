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

ll a[maxn], b[maxn];
struct node {
    ll val;
    int idx;
};

bool cmp(int a, int b)
{
    return a > b;
}

priority_queue<node, vector<node>>q;

int main()
{
    int T = 1, n, ans = 0, m, k, cur;
    ll sum = 0;
    // scanf("%d", &T);
    while (T--) {
        ans = 0, cur = 0;
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n, cmp);
        for (int i = 1; i <= k * m; ++i) {
            if (b[i] == b[k * m])
                ++ans;
            sum += b[i];
        }
        printf("%lld\n", sum);
        for (int i = 1; i <= n; ++i) {
            if (a[i] > b[k * m]) {
                ++cur;
                if (cur >= k * m)
                    break;
                if (cur % m == 0)
                    printf("%d ", i);
            }
            else if (ans && a[i] == b[k * m]) {
                ++cur, --ans;
                if (cur >= k * m)
                    break;
                if (cur % m == 0)
                    printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}