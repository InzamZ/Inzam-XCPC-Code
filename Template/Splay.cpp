#include <bits/stdc++.h>
using namespace std;
#define maxn 1000100
using val_t = long long;
int sz[maxn << 2], son[maxn << 2][2], fa[maxn << 2], cnt[maxn << 2];
val_t val[maxn << 2];
int rt = 0, tot = 0;
struct Splay {
public:
    void maintain(int x)
    {
        sz[x] = sz[son[x][0]] + sz[son[x][1]] + cnt[x];
    }
    bool getson(int x)
    {
        return son[fa[x]][1] == x;
    }
    void clear(int x)
    {
        son[x][0] = son[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
    }
    void splay(int x)
    {
        for (int f = fa[x]; f = fa[x], f; rotate(x)) {
            if (fa[f])
                rotate(getson(x) == getson(f) ? f : x);
        }
        rt = x;
    }
    void rotate(int x)
    {
        int flag = getson(x), y = fa[x], z = fa[y];
        son[y][flag] = son[x][flag ^ 1];
        if (son[x][flag ^ 1])
            fa[son[x][flag ^ 1]] = y;
        son[x][flag ^ 1] = y;
        fa[y] = x;
        fa[x] = z;
        if (z)
            son[z][y == son[z][1]] = x;
        maintain(x);
        maintain(y);
    }
    void insert(val_t k)
    {
        if (!rt) {
            val[++tot] = k;
            ++cnt[tot];
            rt = tot;
            maintain(rt);
            return ;
        }
        int cur = rt, f = 0;
        while (1) {
            if (val[cur] == k) {
                ++cnt[cur];
                maintain(cur);
                maintain(f);
                splay(cur);
                break;
            }
            f = cur;
            cur = son[cur][val[cur] < k];
            if (!cur) {
                tot++;
                fa[tot] = f;
                val[tot] = k;
                ++cnt[tot];
                son[f][val[f] < k] = tot;
                maintain(tot);
                maintain(f);
                splay(tot);
                break;
            }
        }
    }
    val_t find_kth(int k)
    {
        int cur = rt;
        while (1) {
            if (son[cur][0] && k <= sz[son[cur][0]])
                cur = son[cur][0];
            else if ( k <= cnt[cur] + sz[son[cur][0]]) {
                splay(cur);
                return val[cur];
            }
            else
                k -= (cnt[cur] + sz[son[cur][0]]), cur = son[cur][1];
        }
    }
    int find_rk(val_t k)
    {
        int cur = rt, rk = 0;
        while (1) {
            if (val[cur] > k)
                cur = son[cur][0];
            else {
                rk += sz[son[cur][0]];
                if (k == val[cur]) {
                    splay(cur);
                    return rk + 1;
                }
                rk += cnt[cur];
                cur = son[cur][1];
            }
        }
    }
    int pre()
    {
        int cur = son[rt][0];
        while (son[cur][1])
            cur = son[cur][1];
        splay(cur);
        return cur;
    }
    int nxt()
    {
        int cur = son[rt][1];
        while (son[cur][0])
            cur = son[cur][0];
        splay(cur);
        return cur;
    }
    void del(int k)
    {
        find_rk(k);
        if (cnt[rt] > 1) {
            --cnt[rt];
            maintain(rt);
            return ;
        }
        if (!son[rt][0] && !son[rt][1]) {
            clear(rt);
            rt = 0;
            return ;
        }
        if (!son[rt][0]) {
            int cur = rt;
            rt = son[rt][1];
            fa[rt] = 0;
            clear(cur);
            return ;
        }
        if (!son[rt][1]) {
            int cur = rt;
            rt = son[rt][0];
            fa[rt] = 0;
            clear(cur);
            return ;
        }
        int cur = rt, x = pre();
        fa[son[cur][1]] = x;
        son[x][1] = son[cur][1];
        clear(cur);
        maintain(rt);
        return ;
    }
} T;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1)
            T.insert(x);
        if (op == 2)
            T.del(x);
        if (op == 3)
            printf("%d\n", T.find_rk(x));
        if (op == 4)
            printf("%lld\n", T.find_kth(x));
        if (op == 5) {
            T.insert(x);
            printf("%lld\n", val[T.pre()]);
            T.del(x);
        }
        if (op == 6) {
            T.insert(x);
            printf("%lld\n", val[T.nxt()]);
            T.del(x);
        }
        // cout << endl << 1 << endl;
    }
    return 0;
}