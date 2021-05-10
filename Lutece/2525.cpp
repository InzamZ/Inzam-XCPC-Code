#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;

struct node {
    int ids, val;
    node(int x, int y): ids(x), val(y) {}
};
vector<node>s[maxn];
bool flag[maxn], child[maxn];
int ans,cnt[maxn],imax=0;
queue<int>q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, b;
    cin >> n >> k;
    ans=k;
    for (int i = 1; i <= k; ++i) {
        cin >> a >> b;
        s[a].push_back(node(i, b));
        s[b].push_back(node(i, a));
        ++cnt[a];++cnt[b];
        if (cnt[imax]<cnt[a]) imax=a;
        if (cnt[imax]<cnt[b]) imax=b;
    }
    q.push(imax);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < s[cur].size(); ++i) {
            if (!flag[s[cur][i].val] && !child[s[cur][i].ids]) {
                --ans;
                flag[s[cur][i].val] = child[s[cur][i].ids] = 1;
                q.push(s[cur][i].val);
            }
        }
    }
    cout << ans << endl;
    return 0;
}