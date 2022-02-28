//InzamZ

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, t;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        int ans = min(x, y) * 2 + 1 + (max(x, y) - min(x, y) - 1) * 2;
        if (x != y)
            cout << ans << endl;
        else
            cout << x * 2 << endl;
    }
    return 0;
}
