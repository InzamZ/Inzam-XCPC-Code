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

int a[maxn];

vector<int>b;

int main()
{
    int T = 1, n, ans = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        b.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            a[i] = (i + a[i]) % n;
            if (a[i] < 0)
                a[i] += n;
            b.push_back(a[i]);
        }
        int len = b.size();
        sort(b.begin(), b.end());
        int tot = unique(b.begin(), b.end()) - b.begin();
        printf("%s\n", len == tot ? "Yes" : "No");
    }
    return 0;
}