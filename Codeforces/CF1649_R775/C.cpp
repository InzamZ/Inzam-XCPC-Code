//InzamZ
//
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 3400 + 10;
const int maxb = 1e5 + 10;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

vector<long long>row[maxb], col[maxb];
ll ans = 0;

int main()
{
    int T = 1, n, m,a;
    // T=_read();
    while (T--) {
        ans = 0;
        cin >> n >> m;
        for (int i = 1;i <= n;++i)
        {
            for (int j = 1;j<=m;++j)
            {
                cin >> a;
                row[a].push_back(i);
                col[a].push_back(j);
            }
        }
        for (int i = 0;i <= 100000;++i)
        {
            sort(row[i].begin(),row[i].end());
            sort(col[i].begin(),col[i].end());
            ll siz;
            siz = row[i].size();
            for (int j = 0;j < siz;++j)
            {
                ans += (2 * j + 1 - siz) * row[i][j];
            }
            siz = col[i].size();
            for (int j = 0;j < siz;++j)
            {
                ans += (2 * j + 1 - siz) * col[i][j];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
