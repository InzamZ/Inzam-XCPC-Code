#include <bits/stdc++.h>
using namespace std;

#define maxn 200010
typedef long long ll;
ll num[maxn], k, ans;
ll n, m, qr, ql, tot = 0, rt = 0;
#define lo (tree[o].son[0])
#define ro (tree[o].son[1])
#define len(a,b) ((b)-(a)+1)

char s[maxn];

struct node {
    ll sumx, sumy;
    ll lazye, lazys, lazyw, lazyn;
    ll vale, vals, valw, valn;
    ll son[2];
} tree[maxn * 4];

void pushup(ll o)
{
    tree[o].sumx = tree[lo].sumx + tree[ro].sumx;
    tree[o].sumy = tree[lo].sumy + tree[ro].sumy;
    tree[o].vale = tree[lo].vale + tree[ro].vale;
    tree[o].vals = tree[lo].vals + tree[ro].vals;
    tree[o].valw = tree[lo].valw + tree[ro].valw;
    tree[o].valn = tree[lo].valn + tree[ro].valn;
}

void build(ll o, ll L, ll R)
{
    tree[o].lazye = tree[o].lazys = tree[o].lazyw = tree[o].lazyn = 0;
    if (L == R) {
        tree[o].vale = tree[o].valn = tree[o].vals = tree[o].valw = 0;
        if (s[L - 1] == 'E') {
            tree[o].vale = 1;
            tree[o].sumx = 1;
            tree[o].sumy = 0;
        }
        else if (s[L - 1] == 'S') {
            tree[o].vals = 1;
            tree[o].sumx = 0;
            tree[o].sumy = -1;
        }
        else if (s[L - 1] == 'W') {
            tree[o].valw = 1;
            tree[o].sumx = -1;
            tree[o].sumy = 0;
        }
        else {
            tree[o].valn = 1;
            tree[o].sumx = 0;
            tree[o].sumy = 1;
        }
        return ;
    }
    ll M = (L + R) / 2;
    tree[o].son[0] = ++tot;
    build(lo, L, M);
    tree[o].son[1] = ++tot;
    build(ro, M + 1, R);
    pushup(o);
}
void pushdown(ll o, ll L, ll R)
{
    tree[lo].lazye += tree[o].lazye;
    tree[ro].lazye += tree[o].lazye;
    tree[lo].lazys += tree[o].lazys;
    tree[ro].lazys += tree[o].lazys;
    tree[lo].lazyw += tree[o].lazyw;
    tree[ro].lazyw += tree[o].lazyw;
    tree[lo].lazyn += tree[o].lazyn;
    tree[ro].lazyn += tree[o].lazyn;
    //
    tree[lo].sumx += tree[lo].vale * tree[o].lazye;
    tree[lo].sumy -= tree[lo].vals * tree[o].lazys;
    tree[lo].sumx -= tree[lo].valw * tree[o].lazyw;
    tree[lo].sumy += tree[lo].valn * tree[o].lazyn;
    tree[ro].sumx += tree[ro].vale * tree[o].lazye;
    tree[ro].sumy -= tree[ro].vals * tree[o].lazys;
    tree[ro].sumx -= tree[ro].valw * tree[o].lazyw;
    tree[ro].sumy += tree[ro].valn * tree[o].lazyn;
    pushup(o);
    tree[o].lazye = tree[o].lazys = tree[o].lazyw = tree[o].lazyn = 0;
}

pair<ll, ll> getsum(ll o, ll L, ll R)
{
    pair<ll, ll> res = {0, 0};
    if (ql <= L && R <= qr)
        return {tree[o].sumx, tree[o].sumy};
    pushdown(o, L, R);
    ll M = (L + R) / 2;
    if ( M >= ql) {
        auto tmp = getsum(lo, L, M);
        res.first += tmp.first;  
        res.second += tmp.second;
    }
    if ( M < qr ) {
        auto tmp = getsum(ro, M + 1, R);
        res.first += tmp.first;
        res.second += tmp.second;
    }
    return res;
}

void addval(ll o, ll L, ll R, int kinds)
{
    if (ql <= L && R <= qr) {
        if (kinds == 0) {
            tree[o].lazye += 1;
            tree[o].sumx += tree[o].vale;
        }
        else if (kinds == 1) {
            tree[o].lazys += 1;
            tree[o].sumy -= tree[o].vals;
        }
        else if (kinds == 2) {
            tree[o].lazyw += 1;
            tree[o].sumx -= tree[o].valw;
        }
        else {
            tree[o].lazyn += 1;
            tree[o].sumy += tree[o].valn;
        }
        return ;
    }
    pushdown(o, L, R);
    ll M = (L + R) / 2;
    if ( M >= ql )
        addval(lo, L, M, kinds);
    if ( qr > M )
        addval(ro, M + 1, R, kinds);
    pushup(o);
}
int main()
{
    scanf ("%lld %lld", &n, &m);
    scanf("%s", s);
    build(rt, 1, n);
    for (int i = 1; i <= m; i++) {
        ll op;
        scanf ("%lld %lld %lld", &op, &ql, &qr);
        if (ql > qr)
            swap(ql, qr);
        if (op == 1) {
            scanf ("%s", s);
            if (s[0] == 'E')
                k = 0;
            else if (s[0] == 'S')
                k = 1;
            else if (s[0] == 'W')
                k = 2;
            else
                k = 3;
            addval(rt, 1, n, k);
        }
        if (op == 2) {
            scanf ("%lld", &k);
            auto ans = getsum(rt, 1, n);
            ll x = 0, y = 0;
            x += ans.first * (k / (qr - ql + 1));
            y += ans.second * (k / (qr - ql + 1));
            if (k % (qr - ql + 1)) {
                qr = ql + k % (qr - ql + 1) - 1;
                ans = getsum(rt, 1, n);
                x += ans.first;
                y += ans.second;
            }
            printf ("%lld %lld\n", x, y);
        }
    }
    return 0;
}