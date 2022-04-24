//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
ll T = 1, n, ans = 0;
map<string, ll>mp;
ll cnt1[20], cnt2[20];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0; mp.clear();
        for (int i = 0; i <= 'k' - 'a'; ++i)
            cnt1[i] = cnt2[i] = 0;
        cin >> n;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            if (mp.find(s) == mp.end())
                mp[s] = 1;
            else
                mp[s]++;
            cnt1[s[0] - 'a']++;
            cnt2[s[1] - 'a']++;
        }
        for (int i = 0; i <= 'k' - 'a'; ++i) {
            ans += (cnt1[i] * (cnt1[i] - 1) / 2);
            ans += (cnt2[i] * (cnt2[i] - 1) / 2);
        }
        for (auto x : mp) {
            if (x.second > 1)
                ans -= x.second * (x.second - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}