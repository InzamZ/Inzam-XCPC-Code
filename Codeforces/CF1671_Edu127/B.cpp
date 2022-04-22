//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;
vector<int>q;
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 1;
        cin >> n;
        q.clear();
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            q.push_back(a);
        }
        for (int i = q[0] - 1; i <= q[0] + 1; ++i) {
            ans = 1;
            int cur = i;
            for (int j = 0; j < q.size(); ++j) {
                if (cur == q[j] || cur == q[j] + 1 || cur == q[j] - 1)
                    ++cur;
                else {
                    ans = 0;
                    break;
                }
            }
            if (ans)
                break;
        }
        if (ans)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}