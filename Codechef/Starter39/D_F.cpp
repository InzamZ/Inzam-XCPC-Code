//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn],v;
string s;

int solve() {
    ans = 1;
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'c' || s[i] == 'g' || s[i] == 'l' || s[i] == 'r') 
        {
            ans = ans * 2 ;
            ans %= 1000000007ll;
        }
    }
    cout << ans << '\n';
    return 0;
}
//cglr
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
    // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}