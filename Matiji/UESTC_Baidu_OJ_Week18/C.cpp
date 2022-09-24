//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
int T = 1, n, op, x;
priority_queue<int> q;

int solve() {
    cin >> n;
    for (int i = 1; i <= n ; ++i)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x;
            q.push(x);
            break;
        case 2:
            cout << q.top() << '\n';
            break;
        case 3:
            q.pop();
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