//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 50;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;
char s[maxn];

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

int main()
{
    int T = 1, n, ans = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        bool a = 0, b = 0, c = 0, flag = 1;
        for (int i = 0; i < 6 && flag; ++i) {
            if (s[i] == 'r' )
                a = 1;
            if (s[i] == 'b' )
                b = 1;
            if (s[i] == 'g' )
                c = 1;
            if (s[i] == 'R' && !a)
                flag = 0;
            if (s[i] == 'B' && !b)
                flag = 0;
            if (s[i] == 'G' && !c)
                flag = 0;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}