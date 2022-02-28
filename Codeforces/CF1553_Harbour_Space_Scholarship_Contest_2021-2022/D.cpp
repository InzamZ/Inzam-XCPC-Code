#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e6+ 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

// inline char nc()
// {
//     static char buf[100000], *p1 = buf, *p2 = buf;
//     return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
// }
// inline int read()
// {
//     char ch = nc(); int sum = 0;
//     while (!(ch >= '0' && ch <= '9'))
//         ch = nc();
//     while (ch >= '0' && ch <= '9')
//         sum = sum * 10 + ch - 48, ch = nc();
//     return sum;
// }

char s1[maxn], s2[maxn];
int ans = 10;

int main()
{
    int T = 1, n, i;
    scanf("%d", &T);
    while (T--) {
        bool flag = false;
        scanf("%s", s1);
        scanf("%s", s2);
        int delta = strlen(s1) - strlen(s2), cur = 0;
        if (delta >= 0)
            for (int i = delta % 2; i < strlen(s1) && cur < strlen(s2); ) {
                if (s1[i] != s2[cur])
                    i += 2;
                else ++cur, ++i;
            }
        if (cur == strlen(s2))
            flag = true;
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}