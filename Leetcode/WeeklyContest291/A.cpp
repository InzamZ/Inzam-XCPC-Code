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
    string removeDigit(string number, char digit)
    {
        string ans = ""; int id = 0;
        for (int i = 0; i < number.size(); ++i) if (number[i] == digit) id = i;;
        for (int i = 0; i < number.size(); ++i) {
            if ( i == id || (number[i] == digit && number[i + 1] > digit)) {
                ans += number.substr(i + 1);
                break;
            }
            else
                ans += number[i];
        }
        return ans;
    }
};