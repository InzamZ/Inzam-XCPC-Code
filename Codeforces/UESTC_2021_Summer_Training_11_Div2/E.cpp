#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

// int a[15] = {5, 21, 12, 1, 1, 5, 7, 1, 4, 4, 0};
// 5 21 12 
int a[20] = {5, 21, 12, 1, 1, 3, 5, 1, 4, 4, 0, 0, 1, 1, 0};

int main()
{
    int T = 1, n, ans = 0;
    // scanf("%d",&T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}