#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int main()
{
    int T = 1, n;
    bool flag = false;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        flag = false;
        for (int i = 1; !flag && i * i <= n; ++i) {
            if (n % i)
                continue;
            double a = i, b = n / i;
            if (a / b >= 0.5)
                flag = true;
        }
        if (flag)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}