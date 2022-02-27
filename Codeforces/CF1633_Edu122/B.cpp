//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 2e5 + 10;
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

char s[maxn];

int main()
{
    int T = 1, n, ans = 0, len, cnt0, cnt1;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        cnt0 = cnt1 = 0;
        scanf("%s", s);
        len = strlen(s);
        for (int i = 0; i < len; ++i)
            if (s[i] == '0')
                ++cnt0;
            else ++cnt1;
        if (cnt0 == cnt1)
            printf("%d\n", cnt0 - 1);
        else
            printf("%d\n", min(cnt0, cnt1));
    }
    return 0;
}