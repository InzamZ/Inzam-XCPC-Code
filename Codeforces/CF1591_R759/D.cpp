//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 5e5 + 10;
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

int a[maxn];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    int T = 1, n, k;
    ll ans = 0, tmp = 0;
    scanf("%d", &T);
    while (T--) {
        bool flag = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        if (n >= 4 || n == 1)
            flag = 1;
        else if (n == 2 && a[1] > a[2])
            flag = 0;
        else if (n == 3) {
            flag = 1;
            if (a[1] == a[2] || a[2] == a[3])
                flag = 1;
            if (a[1] < a[3] && a[2] < a[3] && a[1] > a[2])
                flag = 0;
            if (a[1] < a[2] && a[2] > a[3])
                flag = 0;
            if (a[1] > a[2] && a[1] > a[3] && a[2] > a[3])
                flag = 0;
        }
        else
            flag = 1;
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}