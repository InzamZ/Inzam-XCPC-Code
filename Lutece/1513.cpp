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
    while (T--) {
        vector<string> v;
        string s1;
        cin >> s1;
        string s11 = s1 + s1;
        for (int i = 1; i < s1.length(); ++i)
            v.push_back(s11.substr(i, s1.length()));
        sort(v.begin(), v.end());
        cout << v[0] << endl;
    }
    return 0;
}