#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int T = 1, ans = 0, a[maxn], n, tmp = 0;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (register int i = 1; i <= n ; ++i) {
        cin >> a[i];
        if (a[i] == 1)
            ++tmp;
        else if (a[i] == 3)
            ans = max(ans, tmp + 1);
        else
            tmp = max(tmp, 1);
    }
    cout << max(ans, tmp) << '\n';
    return 0;
}
