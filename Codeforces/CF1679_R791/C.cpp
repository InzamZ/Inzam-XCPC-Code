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
int T = 1, n, m, q, ans = 0, a[maxn], b[maxn];
int aa[maxn], bb[maxn];

class FenwickTree {
  public:
    int n, ta[maxn];
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int i, int val) {
        int x = i;
        while (i <= n) {
            ta[i] += val;
            i += lowbit(i);
        }
    }
    int getsum(int i) {
        int res = 0, x = i;
        while (i > 0) {
            res += ta[i];
            i -= lowbit(i);
        }
        return res;
    }
} A, B;

int solve() {
    ans = 0;
    cin >> n >> q;
    for (int i = 0; i <= n; ++i)
        B.ta[i] = A.ta[i] = 0 ;
    A.n = B.n = n;
    for (int i = 1; i <= q; ++i) {
        int op, x2, y2, x1, y1;
        cin >> op;
        if (op == 1) {
            cin >> x1 >> y1;
            if (aa[x1] == 0)
                A.update(x1, 1);
            aa[x1]++;
            if (bb[y1] == 0)
                B.update(y1, 1);
            bb[y1]++;
        }
        if (op == 2) {
            cin >> x1 >> y1;
            aa[x1]--; bb[y1]--;
            if (!aa[x1])
                A.update(x1, -1);
            if (!bb[y1])
                B.update(y1, -1);
        }
        if (op == 3) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap (y1, y2);
            int tmp1 = A.getsum(x2) - A.getsum(x1 - 1), tmp2 = B.getsum(y2) - B.getsum(y1 - 1);
            if (tmp1 >= (x2 - x1 + 1) || tmp2  >= (y2 - y1 + 1))
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
        }
    }
    return 0;
}

signed main() {
    FIO;
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}