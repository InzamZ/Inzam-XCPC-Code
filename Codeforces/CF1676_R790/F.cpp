// //InzamZ
// //
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// #define pii pair<int,int>
// #define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
// #define FIO std::ios::sync_with_stdio(false);\
//             std::cin.tie(0)
// #define FFFOUT freopen("./out.txt" , "w", stdout)
// #define FFFIN freopen("./in.txt" , "r", stdin)
// const int maxn = 5e5 + 10;
// const int maxb = 110;
// int T = 1, n, m, x, ans = 0, ansl, cnt, lst;
// int a[maxn];
// map<int, int>mp;
// signed main()
// {
//     FIO;
//     cin >> T;
//     while (T--) {
//         bool flag = 0;
//         ansl = cnt = lst = 0;
//         ans = -1;
//         ++cnt;
//         cin >> n >> m;
//         for (int i = 1; i <= n + 1; i++) {
//             if (i != n + 1)
//                 cin >> a[i];
//             else
//                 a[i] = 0;
//             mp[a[i]]++;
//             if (i == 1) {
//                 lst = a[i];
//                 continue;
//             }
//             if (a[i] == a[i - 1])
//                 cnt++;
//             else {
//                 if (a[i] == a[i - 1] + 1) {
//                     if (cnt < m) {
//                         if (a[i - 1] - lst > ans) {
//                             ans = a[i - 1] - 1 - lst;
//                             ansl = lst;
//                         }
//                         lst = a[i];
//                     }
//                 }
//                 else {
//                     if (a[i - 1] - lst > ans) {
//                         ans = a[i - 1] - lst;
//                         ansl = lst;
//                     }
//                     lst = a[i];
//                 }
//                 cnt = 1;
//             }
//         }
//         for (int i = 1; i <= n; ++i) {
//             if (mp[a[i]] >= m)
//                 flag = 1;
//         }
//         if (flag)
//             cout << ansl << ' ' << ansl + ans << '\n';
//         else
//             cout << -1 << '\n';
//     }
//     return 0;
// }
//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, ansl, cnt, lst;
int a[maxn];
map<int, int>mp;
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        bool flag = 0;
        mp.clear();
        ansl = cnt = lst = 0;
        ans = -1;
        cnt = 1;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        lst = a[1];
        a[n + 1] = 0;
        for (int i = 1; i <= n + 1; i++) {
            if (i != n + 1)
                mp[a[i]]++;
            if (a[i] == a[i - 1])
                ++cnt;
            else {
                if (cnt < m) {
                    if (ans < a[i - 1] - 1 - lst)
                        ansl = lst;
                    ans = max(ans, a[i - 1] - 1 - lst);
                    lst = a[i];
                }
                else {
                    if (a[i] != a[i - 1] + 1) {
                        if (ans < a[i - 1] - lst)
                            ansl = lst;
                        ans = max(ans, a[i - 1] - lst);
                        lst = a[i];
                    }
                }
                cnt = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (mp[a[i]] >= m)
                flag = 1;
        }
        if (flag)
            cout << ansl << ' ' << ansl + ans << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}