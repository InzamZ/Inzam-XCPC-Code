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
int T = 1, n, m, x, ans = 0;
vector<char>v;
stack<char>st;
string s;

int solve() {
    ans = 0;
    cin >> n;
    if (n < 0) {
        n = -n;
        cout << '-';
    }
    if (n == 0)
        cout << '0';
    while (n) {
        st.push(v[n % 36]);
        n /= 36;
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << '\n';
    return 0;
}

signed main() {
    FIO;
    for (int i = 0; i <= 9; ++i)
        v.push_back(i + '0');
    for (int i = 0; i <= 25; ++i)
        v.push_back(i + 'A');
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}