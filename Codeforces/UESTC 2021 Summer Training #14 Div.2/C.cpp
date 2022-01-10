//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 4e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

ll q[maxn][2], cnt[maxn];
ll sum[maxn];
vector<ll>v;
map<ll, int>idx;

#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll _read()
{
    char ch = nc(); ll sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

int main()
{
    int T = 1, n, ans = 0;
    // T=_read();
    while (T--) {
        ans = 0;
        n = _read();
        for (int i = 1; i <= n; ++i) {
            q[i][0] = _read(); q[i][1] = _read();
            idx[q[i][0]]++;
            idx[q[i][1] + 1]--;
            v.push_back(q[i][0]);
            v.push_back(q[i][1] + 1);
        }
        sort(v.begin(), v.end());
        int siz = unique(v.begin(), v.end()) - v.begin();
        ll res = 0;
        for (int i = 0; i < siz - 1; ++i) {
            ll num = v[i + 1] - v[i];
            res += idx[v[i]];
            cnt[res] += num;
        }
        for (int i = 1; i <= n; ++i)
            printf("%lld ", cnt[i]);
    }
    return 0;
}