//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 1e6 + 10;
const int maxb = 110;

stack<int>q;
vector<int>e[maxn];
map<int, int>mp;
int node_cnt = 0, n, m, inst[maxn], a[maxn];
int dfn[maxn], low[maxn], Index = 0;
int belong[maxn], bcnt = 0, ly[maxn], cnt[maxn];
void tarjan(int rt, int fa) {
    low[rt] = dfn[rt] = ++Index;
    q.push(rt);
    inst[rt] = true;
    for (auto v : e[rt]) {
        if (v == fa)
            continue;
        if (!dfn[v]) {
            tarjan(v, rt);
            low[rt] = min(low[rt], low[v]);
        }
        else if (inst[v])
            low[rt] = min(low[rt], dfn[v]);
    }
    if (dfn[rt] == low[rt]) {
        int j;
        bcnt++;
        do {
            j = q.top();
            q.pop();
            inst[j] = false;
            cnt[bcnt]++;
            belong[j] = bcnt;
        }
        while (j != rt);
    }
}
signed main() {
    scanf("%lld", &m);
    while (m-- ) {
        int ans = 0;
        scanf ("%lld", &n);
        for (int i = 1; i <= 2 * n; i++) {
            ly[i] = low[i] = dfn[i] = inst[i] = cnt[i] = 0;
            bcnt = 0;
            e[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf ("%lld", &a[i]);
            mp[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            int u;
            scanf ("%lld", &u);
            e[mp[u]].push_back(i + n);
            e[i + n].push_back(mp[u]);
            e[i + n].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            if (!dfn[i])
                tarjan(i, 0);
        }
        sort(cnt + 1, cnt + 1 + bcnt, greater<int>());
        for (int i = 1; i <= bcnt; i++)
            cnt[i] /= 2;
        int l = 1, r = n;
        for (int i = 1; i <= bcnt; i++) {
            int cur = r, fir = r;
            --r;
            cout << cnt[i] << endl;
            if (cnt[i] == 1) {
                ans += 2 * (r - l);
                --r;
                --l;
            }
            else {
                for (int j = 1; j < cnt[i]; j++) {
                    if (j & 1) {
                        ans += abs(cur - l);
                        cur = l;
                        ++l;
                    }
                    else {
                        ans += abs(cur - r);
                        cur = r;
                        --r;
                    }
                    // cout << ans << '\n';
                }
                ans += abs(cur - fir);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}