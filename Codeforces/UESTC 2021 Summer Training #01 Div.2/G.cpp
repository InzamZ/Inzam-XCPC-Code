#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e4;

char str[maxn];
int cost = 0, cnt[maxn];
int main()
{
    int T = 1, n, len;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        cost = 0; len = strlen(str);
        for (int i = 0; i < len; ++i) {
            if (str[i] == '0' && i)
                cnt[i] = cnt[i - 1] + 1;
            else if (i == 0)
                cnt[i] = str[i] == '0' ? 1 : 0;
            else
                cnt[i] = cnt[i - 1];
        }
        cost = min(cnt[len - 1], len - cnt[len - 1]);
        for (int i = 1; i < len; ++i)
            cost = min(cost, min(cnt[i - 1], i - cnt[i - 1]) + min(cnt[len - 1] - cnt[i - 1], len - i - cnt[len - 1] + cnt[i - 1]));
        printf("%d\n", cost);
        for (int i = 0; i < len; ++i)
            str[i] = cnt[i] = 0;
    }
    return 0;
}