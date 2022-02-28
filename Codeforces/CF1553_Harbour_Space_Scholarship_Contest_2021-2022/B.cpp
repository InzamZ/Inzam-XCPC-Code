#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e3 + 10;
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

char s1[maxn], s2[maxn], s3[maxn], s4[maxn];

bool check(int x)
{
    int cnt = 0;
    memset(s3, 0, sizeof(s3));
    memset(s4, 0, sizeof(s4));
    for (int i = 0; i <= x; ++i)
        s3[cnt++] = s1[i];
    for (int i = x - 1; i >= 0; --i)
        s3[cnt++] = s1[i];
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j < strlen(s2); ++j)
            s4[j] = s3[i + j];
        if (strcmp(s4, s2) == 0)
            return true;
    }
    return false;
}

int main()
{
    int T = 1, n, ans = 0, i;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        bool flag = false;
        scanf("%s", s1);
        scanf("%s", s2);
        for (int i = 0; !flag && i < strlen(s1); ++i)
            if (check(i))
                flag = true;
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}