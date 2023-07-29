//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 1e6 + 10;
const int maxb = 110;
int T = 1, n, q, k, siz, head = 1, ans = 0, a[maxn], b[maxn];
int fenwick[maxn];

void add(int x, int v) {
    for (; x <= n; x += x & -x)
        fenwick[x] += v;
}

int query(int x) {
    int res = 0;
    for (; x; x -= x & -x)
        res += fenwick[x];
    return res;
}

int solve() {
    head = ans = 0;
    cin >> n >> q;
    siz = n;
    for (int i = 1; i <= n; ++i){
        add(i, 1);
    }
    for (int i = 1; i <= q; ++i) {
        cin >> k;
        k %= siz;
        int res = query(n) - query(head);
        if (k == 0) {
            k = siz;
        }
        // cout << "res: " << res << ' ' << "k: " << k << '\n' ;

        if (res >= k) {
            int l = head + 1, r = n, tmp = query(head);
            while (l < r) {
                int mid = (l + r) >> 1;
                // cout << "l: " << l << ' ' << "r: " << r << ' ' << "mid: " << mid << '\n';
                // cout << "query(mid): " << query(mid) << '\n';
                if (query(mid) - tmp >= k)
                    r = mid;
                else
                    l = mid + 1;
            }
            add(l, -1);
            head = l;
            cout << l << '\n';
        }
        else {
            k -= res;
            int l = 1, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                // cout << "l: " << l << ' ' << "r: " << r << ' ' << "mid: " << mid << '\n';
                // cout << "query(mid): " << query(mid) << '\n';
                if (query(mid) >= k)
                    r = mid;
                else
                    l = mid + 1;
            }
            add(l, -1);
            head = l;
            cout << l << '\n';
        }
        --siz;
    }
    return 0;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}