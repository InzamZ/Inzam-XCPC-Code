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
class Solution
{
public:
    long long appealSum(string s)
    {
        long long ans = 0;
        queue<int>q[30];
        for (int i = 0; i <= 25; ++i)
            q[i].push(-1);
        for (int i = 0; i < s.size(); ++i)
            q[s[i] - 'a'].push(i);
        for (int i = 0; i <= 25; ++i)
            q[i].push(s.size());
        for (int i = 0; i <= 25; ++i) {
            while (!q[i].empty()) {
                int a = q[i].front();
                q[i].pop();
                if (q[i].empty())
                    break;
                int b = q[i].front();
                ans += 1ll * (b - a) * (s.length() - b);
            }
        }
        return ans;
    }
};
int main()
{
    auto so = Solution();
    cout << so.appealSum("fxfz") << '\n';
    return 0;
}