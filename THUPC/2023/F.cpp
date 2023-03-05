//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 2e6 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn], cnt[maxn], cnt2[maxn];
vector<int>v1, v2;
vector<pii>choise;
string s;
int solve() {
    ans = 0;
    v1.clear();
    v2.clear();
    cin >> n;
    for (int i = 1; i <= 4 * n; i++) {
        cin >> a[i];
        cnt[i] = cnt2[i] = 0;
    }
    for (int i = 1; i <= 4 * n; i++) {
        b[i] = 0;
        if (v1.size() > v2.size() && v1[v2.size()] == a[i]) {
            if (cnt[a[i]] < 2) {
                choise.push_back({v1.size(), v2.size()});
            }
            v2.push_back(a[i]);
            cnt2[a[i]]++;
            if (cnt2[a[i]] > 2) {
                if (choise.empty()) {
                    cout << "No";
                    return 0;
                }
                int rbl = choise.back().first;
                int rbr = choise.back().second;
                choise.pop_back();
                for (int j = rbl; j < v1.size(); j++)
                    cnt[v1[j]]--;
                for (int j = rbr; j < v2.size(); j++)
                    cnt2[v2[j]]--;
                v1.resize(rbl);
                v2.resize(rbr);
                i = rbl + rbr + 1;
                v1.push_back(a[i]);
                cnt[a[i]]++;
                if (cnt[a[i]] > 2) {
                    cout << "No";
                    return 0;
                }
                b[i] = 1;
                continue;
            }
        }
        else if (cnt[a[i]] < 2) {
            v1.push_back(a[i]);
            cnt[a[i]]++;
            b[i] = 1;
        }
        else 
        {
            cout << "No";
            return 0;
        }
    }
    if (v1.size() == v2.size()) {
        cout << "Yes\n";
        for (int i = 1; i <= 4 * n; i++)
            cout << b[i];
    }
    else
        cout << "No";
    return 0;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}