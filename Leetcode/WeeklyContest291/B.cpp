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
int T = 1, n, ans = 0;
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        cout << ans << '\n';
    }
    return 0;
}
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        vector<int>v[1000010] ; int id = 0;
        for (auto x : cards)
            v[x].push_back(id++);
        int ans = -1;
        for (int i = 0; i < 1000001; ++i) {
            if (v[i].size() >= 2) {
                for (int j=1;j<v[i].size();++j) {
                    if (ans == -1) ans = v[i][j] - v[i][j - 1] + 1;
                    else ans = min(ans, v[i][j] - v[i][j - 1] + 1);
                }
            }
        }
        return ans;
    }
};