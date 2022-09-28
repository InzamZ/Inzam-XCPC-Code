#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

struct node {
    int x, y;
};

int p[500005];
int ans[500005];
bool flag1, flag2;

int main()
{
    int T = 1, n;
    scanf("%d", &T);
    while (T--) {
        flag1 = flag2 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &ans[i]);
        int i = 1;
        for (i = 1; i <= n; ++i) {
            if (ans[i] - p[i] > 0 && flag1 == false)
                break;
            if (ans[i] - p[i] < 0 && flag2 == false)
                break;
            if (p[i] == 1)
                flag1 = 1;
            if (p[i] == -1)
                flag2 = 1;
        }
        if (i == n + 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}