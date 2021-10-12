// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// #define pii pair<int,int>
// #define pll pair<ll,ll>
// #define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

// const int maxn = 1e6 + 10;
// const int maxb = 110;
// const int inf = 1e9;
// const ll Inf = 1e18;

// int ans[maxn];

// int main()
// {
//     srand(time(NULL));
//     int T = 1, fa;
//     int cnt = 0, cur = 1, l, n, mid, s;
//     int d, q;
//     // scanf("%d", &T);
//     while (T--) {
//         cnt = 0;
//         scanf("%d", &n);
//         for (int i = 1; i <= n; ++i) {
//             cnt = 0;
//             for (int j = 1; j * j <= i; ++j) {
//                 if (j * j == i)
//                     cnt++;
//                 else if (i % j == 0)
//                     cnt += 2;
//             }
//             if (ans[cnt] == 0)
//                 ans[cnt] = i;
//         }
//     }
//     for (int i = 1; i <= n; ++i)
//         if (ans[i])
//             printf("%d : %d\n", i, ans[i]);
//     return 0;
// }
// /*4
// 8 -1 3 3
// 1 -8
// 1 -8
// 3 10
// */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1010;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

ll ans[maxn];

int main()
{
    int T = 1, n, cnt, mx;
    // scanf("%d",&T);
    while (T--) {
        cnt = 0, mx = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            ans[n] = Inf;
        ans[1] = 1; ans[2] = 2;
        for (int i = 2; i <= 10000; ++i) {
            cnt = 0, mx = 1;
            for (int j = 1; j * j <= i; ++j) {
                if (j * j == i)
                    cnt++, mx = max(mx, j);
                else if (i % j == 0)
                    cnt += 2, mx = max(mx, j);
            }
            ans[2 * cnt - 1] = min(ans[2 * cnt - 1], 1ll * i * i);
            ans[2 * cnt] = min(ans[2 * cnt], 1ll * i * (i + 1));
            // printf("%d %lld %lld\n", i, ans[2 * cnt - 1], ans[2 * cnt]);
        }
        printf("%lld\n", ans[n]);
    }
    return 0;
}
