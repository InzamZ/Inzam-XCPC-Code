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
stack<int>s;

int solve() {
    char ch; ans = 0;
    while ((ch = getchar())!=EOF)
    {
        if (ch <= '9' && ch >= '0')
        {
            ans = ans * 10 + ch - '0';
        }
        else if (ch == '+')
        {
            // if (ans != 0) s.push(ans);
            // ans = 0;
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(a + b);
        }
        else if (ch == '-')
        {
            // if (ans != 0) s.push(ans);
            // ans = 0;
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(b - a);
        }
        else if (ch == '*')
        {
            // if (ans != 0) s.push(ans);
            // ans = 0;
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(a * b);
        }
        else if (ch == ' ')
        {
            if (ans != 0) s.push(ans);
            ans = 0;
        }
    }
    cout << s.top() << '\n';
    return 0;
}

signed main()
{
    FIO;
    // cin >> T;
    while (T--) {
    // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}