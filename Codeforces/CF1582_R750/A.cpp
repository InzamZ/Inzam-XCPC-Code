//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e3 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n, m, q, ans = 0, cnt = 0;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &q);
        int nn = n % 2, mm = m % 2, qq = q % 2;
        if (nn && mm && qq)
            printf("0\n");
        else if (nn && mm)
            printf("1\n");
        else if (qq && mm)
            printf("1\n");
        else if (qq && nn && n >= 3)
            printf("0\n");
        else if (qq && nn && m>=4)
            printf("0\n");
        else if (qq && nn)
            printf("2\n");
        else if (nn)
            printf("1\n");
        else if (mm && q >= 2 && m >= 3)
            printf("0\n");
        else if (mm && n>=2)
            printf("0\n");
        else if (mm)
            printf("2\n");
        else if (qq && m>=2)
            printf("1\n");
        else if (qq && n>=2)
            printf("1\n");
        else if (qq)
            printf("3\n");
        else
            printf("0\n");
    }
    return 0;
}