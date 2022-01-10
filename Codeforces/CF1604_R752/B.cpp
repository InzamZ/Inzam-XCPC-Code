//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n, a[maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        flag = false;
        scanf("%d", &n);
        if (n % 2 == 0)
            flag = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if (i != 1 && a[i - 1] >= a[i])
                flag = 1;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}