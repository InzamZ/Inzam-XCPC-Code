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
int T = 1, n, op, x;
deque<int> q;

int solve() {
    cin >> n;
    for (int i = 1; i <= n ; ++i)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x;
            q.push_front(x);
            break;
        case 2:
            cin >> x;
            q.push_back(x);
            break;
        case 3:
            cout << q.front() << endl;
            break;
        case 4:
            cout << q.back() << endl;
            break;
        case 5:
            q.pop_front();
            break;
        case 6:
            q.pop_back();
            break;
        default:
            break;
        }
    }
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