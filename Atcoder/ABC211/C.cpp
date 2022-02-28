#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll mod = 1e9 + 7;

char s[maxn];
ll f[maxn][10];

int main()
{
    int T = 1, n, ans = 0;
    // scanf("%d",&T);
    memset(f, 0, sizeof(f));
    while (T--) {
        scanf("%s", s);
        for (int i = 0; i < strlen(s); ++i) {
            if (i)
                for (int j = 1; j <= 8; ++j)
                    f[i][j] = f[i - 1][j];
            if (s[i] == 'c')
                f[i][1]++;
            else if (i && s[i] == 'h')
                f[i][2] += (f[i - 1][1]);
            else if (i && s[i] == 'o')
                f[i][3] += (f[i - 1][2]);
            else if (i && s[i] == 'k')
                f[i][4] += (f[i - 1][3]);
            else if (i && s[i] == 'u')
                f[i][5] += (f[i - 1][4]);
            else if (i && s[i] == 'd')
                f[i][6] += (f[i - 1][5]);
            else if (i && s[i] == 'a')
                f[i][7] += (f[i - 1][6]);
            else if (i && s[i] == 'i')
                f[i][8] += (f[i - 1][7]);
            for (int j = 1; j <= 8; ++j)
                f[i][j] %= mod;
        }
        printf("%lld\n", f[strlen(s) - 1][8] % mod);
    }
    return 0;
}