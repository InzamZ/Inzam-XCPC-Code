//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0, cnt;
int a[50];

bool rb(int index)
{
    if (index != n && a[index + 1] == 0)
        return false;
    while (a[index] >= a[index + 1]) {
        if (!a[index])
            return false;
        a[index] >>= 1;
        ++cnt;
    }
    if (index != 1 && a[index - 1] >= a[index])
        return rb(index - 1);
    return true;
}

int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    cin >> T;
    while (T--) {
        ans = 1;
        cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 2; i <= n; ++i) {
            if (a[i - 1] >= a[i]) {
                if (!rb(i - 1)) {
                    ans = 0;
                    break;
                }
            }
        }
        if (ans)
            cout << cnt << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}