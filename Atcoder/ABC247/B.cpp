//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;
string s1, s2;
map <string, int >mp;
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    // cin >> T;
    while (T--) {
        ans = 1;
        cin >> n;
        mp.clear();
        vector<pair<string, string >>v;
        for (int i = 1; i <= n; ++i) {
            cin >> s1 >> s2;
            mp[s1]++;
            mp[s2]++;
            v.push_back({s1, s2});
        }
        for (int i = 0; i < n; ++i) {
            if (v[i].first == v[i].second && mp[v[i].first] > 2) {
                ans = 0;
                break;
            }
            else if (v[i].first != v[i].second && mp[v[i].first] > 1 && mp[v[i].second] > 1) {
                ans = 0;
                break;
            }
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}