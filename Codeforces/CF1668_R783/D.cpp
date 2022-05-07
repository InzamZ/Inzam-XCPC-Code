//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;
int dp[maxn], idx[maxn];
vector<int>pre;

struct node {
    int l, r, id;
    int mx1, mx2, mx3;
} tree[maxn * 4];

void build(int rt, int l, int r)
{
    tree[rt].id = rt;
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].mx1 = tree[rt].mx2 = tree[rt].mx3 = -1ll * 0x3fffffffffffffff;
    if (l == r)
        return ;
    int mid = (l + r) >> 1ll;
    build(rt << 1ll, l, mid);
    build(rt << 1ll | 1ll, mid + 1, r);
}

node query(node &rt, int l, int r)
{
    if (rt.l >= l && rt.r <= r)
        return rt;
    int mid = (rt.l + rt.r) >> 1ll;
    if (r <= mid)
        return query(tree[rt.id << 1ll], l, r);
    else if (l > mid)
        return query(tree[rt.id << 1ll | 1ll], l, r);
    else {
        node ls = query(tree[rt.id << 1ll], l, r);
        node rs = query(tree[rt.id << 1ll | 1ll], l, r);
        node res;
        res.mx1 = max(ls.mx1, rs.mx1);
        res.mx2 = max(ls.mx2, rs.mx2);
        res.mx3 = max(ls.mx3, rs.mx3);
        return res;
    }
}

void update(node &rt, int val, int id, int i)
{
    if (rt.l == rt.r && rt.l == id) {
        rt.mx1 = max(rt.mx1, val - i);
        rt.mx2 = max(rt.mx2, val);
        rt.mx3 = max(rt.mx3, val + i);
        return ;
    }
    int mid = (rt.l + rt.r) >> 1ll;
    if (id <= mid)
        update(tree[rt.id << 1ll], val, id, i);
    else
        update(tree[rt.id << 1ll | 1ll], val, id, i);
    rt.mx1 = max(tree[rt.id << 1ll].mx1, tree[rt.id << 1ll | 1ll].mx1);
    rt.mx2 = max(tree[rt.id << 1ll].mx2, tree[rt.id << 1ll | 1ll].mx2);
    rt.mx3 = max(tree[rt.id << 1ll].mx3, tree[rt.id << 1ll | 1ll].mx3);
}

signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        idx[0] = 0;
        pre.clear();
        for (int i = 1; i <= n; i++) {
            cin >> idx[i];
            idx[i] += idx[i - 1];
            pre.push_back(idx[i]);
        }
        pre.push_back(0);
        sort(pre.begin(), pre.end());
        pre.erase(unique(pre.begin(), pre.end()), pre.end());
        int len = pre.size();
        for (int i = 0; i <= n; i++)
            idx[i] = lower_bound(pre.begin(), pre.end(), idx[i]) - pre.begin() + 1;
        build(1, 1, len);
        dp[0] = 0;
        update(tree[1], 0, idx[0], 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = -1ll * 0x3fffffffffffffff;
            if (idx[i] > 1) {
                node res = query(tree[1], 1, idx[i] - 1);
                dp[i] = max(dp[i], res.mx1 + i);
            }
            if (idx[i] < len) {
                node res = query(tree[1], idx[i] + 1, len);
                dp[i] = max(dp[i], res.mx3 - i);
            }
            node res = query(tree[1], idx[i], idx[i]);
            dp[i] = max(dp[i], res.mx2);
            update(tree[1], dp[i], idx[i], i);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}