#include <bits/stdc++.h>
using namespace std;

#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
const int maxn = 2e5 + 10, maxs = 2e6 + 10;
struct imark {
    int num, str;
} ans[maxn];
class Automaton {
  public:
    /**
     * @brief a是匹配串,s是文本串,
     */
    char a[maxn], s[maxs];
    int tot = 0, n, indeg[maxs];
    struct node {
        int f, book, next[26], cnt;
    } tree[maxs];
    /**
     * @brief 对Trie树节点初始化
     */
    void clean(int x) {
        memset(tree[x].next, 0, sizeof(tree[x].next));
        indeg[x] = tree[x].f = tree[x].book = tree[x].cnt = 0;
    }
    /**
     *@brief 对每个字符串更新Trie树,随后调用getfail()
     */
    void build(int x) {
        int cur = 0, l = strlen(a);
        for (int i = 0; i < l; ++i) {
            if (!tree[cur].next[a[i] - 'a']) {
                tree[cur].next[a[i] - 'a'] = ++tot;
                clean(tot);
            }
            cur = tree[cur].next[a[i] - 'a'];
        }
        if (tree[cur].book == 0)
            tree[cur].book = x;
        else
            ans[x].str = tree[cur].book;
    }
    void getfail() {
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
                    indeg[tree[tree[now].next[i]].f]++;
                    q.push(tree[now].next[i]);
                }
                else
                    tree[now].next[i] = tree[tree[now].f].next[i];
        }
    }
    void query() {
        int now = 0, j = -1, l = strlen(s);
        for (int i = 0; i < l; ++i) {
            now = tree[now].next[s[i] - 'a'];
            tree[now].cnt++;
        }
    }
    void topu() {
        queue<int>q;
        for (int i = 0; i <= tot; ++i)
            if (indeg[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans[tree[u].book].num = tree[u].cnt;
            int f = tree[u].f;
            indeg[f]--;
            tree[f].cnt += tree[u].cnt;
            if (indeg[f] == 0)
                q.push(f);
        }
    }
} aca;
signed main() {
    FIO;
    cin >> aca.n;
    aca.tot = 0;
    aca.clean(0);
    for (int i = 1; i <= aca.n; i++) {
        cin >> aca.a;
        ans[i].num = 0; ans[i].str = i;
        aca.build(i);
    }
    cin >> aca.s;
    aca.getfail();
    aca.query();
    aca.topu();
    for (int i = 1; i <= aca.n; i++)
        cout << ans[ans[i].str].num << endl;
    return 0;
}