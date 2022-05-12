#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e2 + 10, maxs = 1e6 + 10, maxtmp = 1e3 + 10;
struct imark {
    int num, str;
    bool operator < (const imark &rhs) const
    {
        if (num == rhs.num)
            return str < rhs.str;
        else
            return num > rhs.num;
    }
} ans[maxs];
class Automaton
{
public:
    static const int maxn = 2e2 + 10, maxs = 1e6 + 10, maxtmp = 1e3 + 10;
    /**
     * @brief a是匹配串,s是文本串,
     */
    char a[maxn][maxtmp], s[maxs];
    int tot = 0;
    struct node {
        int f, book, next[26];
    } tree[maxs];
    /**
     * @brief 对Trie树节点初始化
     */
    void clean(int x)
    {
        memset(tree[x].next, 0, sizeof(tree[x].next));
        tree[x].f = 0;
        tree[x].book = 0;
    }
    /**
     *@brief 对每个字符串更新Trie树,随后调用getfail()
     */
    void build(int x)
    {
        int cur = 0, l = strlen(a[x]);
        for (int i = 0; i < l; ++i) {
            if (!tree[cur].next[a[x][i] - 'a']) {
                tree[cur].next[a[x][i] - 'a'] = ++tot;
                clean(tot);
            }
            cur = tree[cur].next[a[x][i] - 'a'];
        }
        tree[cur].book = x;
    }
    void getfail()
    {
        queue<int> q; tree[0].f = 0;
        for (int i = 0; i < 26; i++)
            if (tree[0].next[i] != 0) {
                tree[tree[0].next[i]].f = 0;
                q.push(tree[0].next[i]);
            }
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int i = 0; i < 26; i++)
                if (tree[now].next[i]) {
                    tree[tree[now].next[i]].f = tree[tree[now].f].next[i];
                    q.push(tree[now].next[i]);
                }
                else
                    tree[now].next[i] = tree[tree[now].f].next[i];
        }
    }
} aca;
int main()
{
//  freopen("testdata.in","r",stdin);
    int n;
    while (scanf ("%d", &n) == 1 && n) {
        aca.tot = 0;
        aca.clean(0);
        for (int i = 1; i <= n; i++) {
            scanf ("%s", aca.a[i]);
            ans[i].num = 0; ans[i].str = i;
            aca.build(i);
        }
        scanf ("%s", aca.s);
        aca.getfail();
        int now = 0, j = -1, l = strlen(aca.s);
        for (int i = 0; i < l; ++i) {
            now = aca.tree[now].next[aca.s[i] - 'a'];
            for (int j = now; j != 0; j = aca.tree[j].f)
                ans[aca.tree[j].book].num++;
        }
        sort(ans + 1, ans + 1 + n);
        printf("%d\n", ans[1].num);
        cout << aca.a[ans[1].str] << endl;
        for (int i = 2; i <= n; i++)
            if (ans[i].num == ans[i - 1].num)
                cout << aca.a[ans[i].str] << endl;
            else
                break;
    }
    return 0;
}