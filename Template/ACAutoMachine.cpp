#include <bits/stdc++.h>
using namespace std;
struct node {
    int f;
    int book;
    int next[26];
} tree[1000051];
struct imark {
    int num, str;
} ans[1000051];
bool cmp(imark a, imark b)
{
    if (a.num == b.num)
        return a.str < b.str;
    else
        return a.num > b.num;
}
char a[155][1000];
void clean(int x)
{
    memset(tree[x].next, 0, sizeof(tree[x].next));
    tree[x].f = 0;
    tree[x].book = 0;
}
char s[1000506];
int ta = 0;
void build(int x)
{
    int cur = 0, l = strlen(a[x]);
    for (int i = 0; i < l; ++i) {
        if (!tree[cur].next[a[x][i] - 'a']) {
            tree[cur].next[a[x][i] - 'a'] = ++ta;
            clean(ta);
        }
        cur = tree[cur].next[a[x][i] - 'a'];
    }
    tree[cur].book = x;
}
int main()
{
//  freopen("testdata.in","r",stdin);
    int n;
    queue<int> q;
    while (scanf ("%d", &n) == 1 && n) {
        ta = 0;
        clean(0);
        for (int i = 1; i <= n; i++) {
            scanf ("%s", a[i]);
            ans[i].num = 0;
            ans[i].str = i;
            build(i);
        }
        scanf ("%s", s);
        tree[0].f = 0;
        for (int i = 0; i < 26; i++) {
            if (tree[0].next[i] != 0) {
                tree[tree[0].next[i]].f = 0;
                q.push(tree[0].next[i]);
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (tree[now].next[i]) {
                    tree[tree[now].next[i]].f = tree[tree[now].f].next[i];
                    q.push(tree[now].next[i]);
                }
                else
                    tree[now].next[i] = tree[tree[now].f].next[i];
            }
        }
        int now = 0, j = -1, l = strlen(s);
        for (int i = 0; i < l; ++i) {
            now = tree[now].next[s[i] - 'a'];
            for (int j = now; j != 0; j = tree[j].f)
                ans[tree[j].book].num++;
        }
        sort(ans + 1, ans + 1 + n, cmp);
        printf("%d\n", ans[1].num);
        cout << a[ans[1].str] << endl;
        for (int i = 2; i <= n; i++) {
            if (ans[i].num == ans[i - 1].num)
                cout << a[ans[i].str] << endl;
            else
                break;
        }
    }
    return 0;
}