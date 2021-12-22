//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef FREAD
static char buf[1000000], *p1 = buf, *p2 = buf, obuf[1000000], *p3 = obuf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
template<typename item>
inline void read(register item &x)
{
    x = 0; register int f = 1; register char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    x *= f;
}
#endif

vector<int>p[maxn];
int T = 1, n, m;

bool check(int x)
{
    int flag1 = 0, flag2 = 1;
    for (int i = 1; !flag1 && i <= m; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (p[i][j] >= x)
                ++cnt;
        }
        if (cnt >= 2)
            flag1 = 1;
    }
    for (int j = 1; flag2 && j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            if (p[i][j] >= x)
                break;
            if (i == m)
                flag2 = 0;
        }
    }
    return flag1 && flag2;
}

int main()
{
    read(T);
    while (T--) {
        read(m); read(n);
        for (int i = 1; i <= m; ++i) {
            p[i].push_back(0);
            int x;
            for (int j = 1; j <= n; ++j) {
                read(x);
                p[i].push_back(x);
            }
        }
        int l = 1, r = 1e9 + 1, mid;
        while (l + 1 < r) {
            mid = (l + r) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%d\n", l);
        for (int i = 1; i <= m; ++i)
            p[i].clear();
    }
    return 0;
}