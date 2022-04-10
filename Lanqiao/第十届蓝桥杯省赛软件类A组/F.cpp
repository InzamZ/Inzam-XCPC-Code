//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n, tmp, ans, ansd = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int cnt = 0, cur = 1, dep = 1, a;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        tmp += a;
        ++cnt;
        if (cur == cnt) {
            if (tmp > ans)
                ans = tmp, ansd = dep;
            tmp = cnt = 0;
            cur *= 2;
            ++dep;
        }
    }
    if (tmp > ans)
        ans = tmp, ansd = dep;
    cout << ansd << '\n';
    return 0;
}