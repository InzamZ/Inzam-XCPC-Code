#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

int T = 1, n;
bool vis[200010];
int a[200010], ans[200010];
struct node {
    int cnt;
    int id;
} b[200010];

bool cmp(node a, node b)
{
    if (a.cnt == b.cnt)
        return a.id < b.id;
    return a.cnt < b.cnt;
}

vector <int>q;
vector <int>p;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        q.clear();
        p.clear();
        for (int i = 0; i <= n; ++i)
            vis[i] = 0, b[i].cnt = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b[i].id = i;
            b[a[i]].cnt++;
        }
        sort(b + 1, b + n + 1, cmp);
        for (int i = 1; i <= n; ++i) {
            if (vis[a[b[i].id]] == 0) {
                vis[a[b[i].id]] = 1;
                ans[b[i].id] = a[b[i].id];
            }
            else
                q.push_back(b[i].id);
        }
        for (int i = 1; i <= n ; ++i) {
            if (vis[i] == 0)
                p.push_back(i);
        }
        sort(q.begin(), q.end());
        for (int i = 0; i < q.size(); ++i) {
            if (q[i] == p[i]) {
                if (i == 0)
                    swap(q[i], q[q.size() - 1]);
                else
                    swap(q[i], q[i - 1]);
            }
        }
        for (int i = 0; i < q.size(); ++i)
            ans[q[i]] = p[i];
        printf("%ld\n", n - q.size());
        for (int i = 1; i <= n; ++i)
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}