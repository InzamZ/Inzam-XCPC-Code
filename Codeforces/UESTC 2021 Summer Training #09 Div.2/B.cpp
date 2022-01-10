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

char s[maxn];
int ans[maxn][2];
int ans2[maxn][2];

int main()
{
    int T = 1, n, b, cntb = 0, cnta = 0;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &b);
        scanf("%s", s);
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'b')
                ++cntb;
            else
                cnta++;
        }
        for (int i = 1, cnt = 0; i <= n; ++i) {
            if (s[i - 1] == 'b')
                ans[++cnt][0] = i ;
        }
        for (int i = 1, cnt = 0; i <= n; ++i) {
            if (s[n - i] == 'b')
                ans[++cnt][1] = i;
        }
        for (int i = 1, cnt = 0; i <= n; ++i) {
            if (s[i - 1] == 'a')
                ans2[++cnt][0] = i ;
        }
        for (int i = 1, cnt = 0; i <= n; ++i) {
            if (s[n - i] == 'a')
                ans2[++cnt][1] = i;
        }
        if (cntb <= b || cnta <= b)
            ans[0][0] = 0;
        else {
            ans[0][0] = min(ans[cntb - b][0], ans[cntb - b][1]);
            ans[0][0] = min(ans[0][0], ans2[cnta - b][1]);
            ans[0][0] = min(ans[0][0], ans2[cnta - b][0]);
            for (int i = 1; i < cntb - b; ++i){
                ans[0][0] = min(ans[0][0], ans[i][0] + ans[cntb - b - i][1]);
            }
            for (int i = 1; i < cnta - b; ++i){
                ans[0][0] = min(ans[0][0], ans2[i][0] + ans2[cnta - b - i][1]);
            }
        }
        printf("%d\n", max(0, n - ans[0][0]));
    }
    return 0;
}