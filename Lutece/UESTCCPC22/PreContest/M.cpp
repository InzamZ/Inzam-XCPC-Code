#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
int n, m, q[maxn];
double ans[maxn];
const int INF = 0x7fffffff / 2;
struct edge {
    int x, s;
} e[maxn];
struct query {
    int t, id;
} Q[maxn];
bool cmp(const edge &x, const edge &y) {
    return x.x < y.x;
}
bool cmp1(const query &x, const query &y) {
    return x.t < y.t;
}
double cal(int x, int t) {
    return 1.0 + (double)(t - e[x].x) / (double)e[x].s;
}
int sanfen(int l, int r, int t) {
    int midl, midr, Ans = l;
    while (l <= r) {
        midl = l + (r - l) / 3; midr = r - (r - l) / 3;
        if (cal(q[midl], t) >= cal(q[midr], t))
            Ans = midl, r = midr - 1;
        else
            Ans = midr, l = midl + 1;
    }
    return Ans;
}
void solve() {
    int i, l = 1, r = 0, top = 1, id;
    Q[m + 1].t = INF;
    for (i = 1; i <= m; i++) {
        while (top <= n && e[top].x <= Q[i].t) {
            if (l <= r && e[top].s >= e[q[r]].s) {
                top++;
                continue;
            }
            while (l <= r && cal(top, Q[i].t) >= cal(q[r], Q[i].t))
                r--;
            q[++r] = top; top++;
        }
        if (l <= r)
            id = sanfen(l, r, Q[i].t), l = id;
        if (l <= r)
            ans[Q[i].id] = cal(q[l], Q[i].t);
        else
            ans[Q[i].id] = -1;
    }
}
int main() {
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d%d", &e[i].x, &e[i].s);
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
        scanf("%d", &Q[i].t), Q[i].id = i;
    sort(e + 1, e + n + 1, cmp); sort(Q + 1, Q + m + 1, cmp1);
    solve();
        for (i = 1; i <= m; i++)if (ans[i] != -1)printf("%.6lf\n", ans[i]); else puts("-1");
    return 0;
}
