//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e6 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

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
        sum = 1ll * sum * 10 + 1ll * (ch - 48), ch = nc();
    return sum;
}
#endif

ll T = 1, n, d;
pii s[maxn];

bool check(int k)
{
    vector<int>q;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            q.push_back(s[i].second);
            ++cnt;
        }
        else {
            auto tmp = upper_bound(q.begin(), q.end(), s[i].second);
            --tmp;
            if ((*tmp + d - 1) < s[i].first) {
                q.push_back(s[i].second);
                ++cnt;
            }
        }
    }
    return cnt <= k;
}

bool cmp(pii x, pii y)
{
    return x.second < y.second;
}

int main()
{
    // T=_read();
    while (T--) {
        n = _read(); d = _read();
        for (int i = 1; i <= n; ++i) {
            s[i].first = _read(); s[i].second = _read();
        }
        sort(s + 1, s + 1 + n, cmp);
        int l = 0, r = n;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            // printf("%d %d\n", l, r);
            if (check(mid))
                r = mid;
            else
                l = mid;
        }
        printf("%d\n", r);
    }
    return 0;
}