//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;

vector<int>ans1;
vector<int>ans2;

int main()
{
    cin >> T;
    for (int i = 1000; i < 10000; ++i) {
        int cnt = i;
        int a = cnt / 1000; cnt = cnt % 1000;
        int b = cnt / 100; cnt = cnt % 100;
        int c = cnt / 10; cnt = cnt % 10;
        int d = cnt;
        int mn = d * 10 + c, dy = b * 10 + a;
        if (mn > 12 || mn < 1)
            continue;
        if (dy > 31 || dy < 1)
            continue;
        if (mn == 2 && dy > 28)
            continue;
        if (mn == 4 || mn == 6 || mn == 9 || mn == 11) {
            if (dy > 30)
                continue;
        }
        ans1.push_back(i * 10000 + d * 1000 + c * 100 + b * 10 + a);
        if (a == c && b == d)
            ans2.push_back(i * 10000 + d * 1000 + c * 100 + b * 10 + a);
    }
    cout << *upper_bound(ans1.begin(), ans1.end(), T) << '\n';
    cout << *upper_bound(ans2.begin(), ans2.end(), T) << '\n';
    return 0;
}