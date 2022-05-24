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
struct inode {
    int va, vb, id;
    inode(int a, int b, int c) : va(a), vb(b), id(c) {}
    bool operator < (const inode &rhs) const {
        if (va != rhs.va)
            return va < rhs.va;
        if (vb != rhs.vb)
            return vb < rhs.vb;
        return id < rhs.id;
    }
};

vector<inode>v, vtmp;
map<inode, int>mp;
vector<pii > aans;

int solve() {
    ans = 1;
    cin >> n;
    aans.clear();
    v.clear();
    vtmp.clear();
    mp.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(inode(a[i], i, i));
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        v[i - 1].vb = b[i];
        mp[v[i - 1]] = i;
    }
    vtmp = v;
    sort(v.begin(), v.end());
    for (int i = 1; i < n ; ++i) {
        if (v[i].va < v[i - 1].va || v[i].vb < v[i - 1].vb)
            ans = 0;
    }
    if (!ans)
        cout << "-1\n";
    else {
        for (int i = 0; i < n; ++i) {
            if (mp[v[i]] != i + 1) {
                aans.push_back(pii(mp[v[i]], i + 1));
                auto t = mp[v[i]];
                mp[vtmp[t - 1]] = i + 1;
                mp[vtmp[i]] = t;
                swap(vtmp[t - 1], vtmp[i]);
            }
        }
        cout << aans.size() << '\n';
        for (auto &i : aans)
            cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}