//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

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

vector<int>v;

int main()
{
    int T = 1, n, ans = 0;
    for (int i = 1; i * i <= 1e9; ++i) {
        v.push_back(i * i);
        if (i <= 1000)
            v.push_back(i * i * i);
    }
    sort(v.begin(), v.end());
    auto end = unique(v.begin(), v.end());
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        upper_bound(v.begin(), end, n);
        printf("%d\n", upper_bound(v.begin(), end, n) - v.begin());
    }
    return 0;
}