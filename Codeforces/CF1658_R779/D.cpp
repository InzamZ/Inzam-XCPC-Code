//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e6 + 10;
int T = 1, l, r, ans = 0;
int p;
set<int>s, s2;

int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        int mul = 1;
        s.clear();
        cin >> l >> r;
        for (int i = l; i <= r; ++i) {
            cin >> p; s.insert(p);
        }
        for (; l % 2 == 0 && r % 2 == 1; l >>= 1, r >>= 1, mul <<= 1) {
            s2.clear();
            for (auto it : s)
                s2.insert(it >> 1);
            swap(s, s2);
        }
        if (l % 2 == 0)
            ans = r;
        else
            ans = l;
        for (int i : s) {
            if (s.find(i ^ 1) == s.end()) {
                int cur = i ^ ans;
                int ok = 1;
                for (int j : s) {
                    if (l > (j ^ cur) || (j ^ cur) > r) {
                        ok = 0; break;
                    }
                }
                if (ok) {
                    ans = cur;
                    break;
                }
            }
        }
        cout << ans *mul << '\n';
    }
    return 0;
}