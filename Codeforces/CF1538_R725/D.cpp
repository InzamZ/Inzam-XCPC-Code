#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

using ll = long long;

int main()
{
    int T = 1, n, a, b, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &k);
        int i=2;
        while (a != 1 ) {
            while (a%i==0) 
            {a/=i;++n;}
        }
    }
    return 0;
}