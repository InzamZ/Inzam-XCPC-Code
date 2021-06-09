#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010
typedef long long ll;
ll n, m, qr, ql, tot = 0, rt = 0, k;
#define lo (2*o)
#define ro (2*o+1)
#define len(a,b) ((b)-(a)+1)

ll num[maxn << 1], cnt = 0;

struct node {
    ll sum1, sum2;
    int lazy, lazy2;
    node(): sum1(0), sum2(0), lazy(0), lazy2(0) {}
} tree[maxn << 2];

void do_odd(ll o, ll L, ll R)
{
    ll all = num[R + 1] - num[L];
    tree[o].sum2 = (all - tree[o].sum2);
}

void pushup(ll o, ll L, ll R)
{
    if (tree[o].lazy)
        tree[o].sum1 = num[R + 1] - num[L];
    else
        tree[o].sum1 = tree[lo].sum1 + tree[ro].sum1;
}

void pushdown(ll o, ll L, ll R)
{
    if (tree[o].lazy2) {
        ll mid = (L + R) >> 1;
        do_odd(lo, L, mid);
        do_odd(ro, mid + 1, R);
        tree[lo].lazy2 ^= 1;
        tree[ro].lazy2 ^= 1;
        tree[o].lazy2 = 0;
    }
}

void addval(ll o, ll L, ll R)
{
    if (num[R + 1] <= ql || num[L] >= qr)
        return ;
    if (ql <= num[L] && num[R + 1] <= qr) {
        tree[o].lazy += k;
        do_odd(o, L, R);
        tree[o].lazy2 ^= 1;
        pushup(o, L, R);
        return ;
    }
    pushdown(o, L, R);
    ll M = (L + R) / 2;
    addval(lo, L, M);
    addval(ro, M + 1, R);
    pushup(o, L, R);
    tree[o].sum2 = tree[lo].sum2 + tree[ro].sum2;
}

struct edge {
    ll l, r, h, flag;
    edge() {}
    edge(ll a, ll b, ll c, ll d): l(a), r(b), h(c), flag(d) {}
} e[maxn << 1];

bool cmp(edge a, edge b)
{
    return a.h < b.h;
}

int main()
{
    ll n, a, b, c, d, sum1 = 0, sum2 = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        if (a > c)
            swap(a, c);
        if (b > d)
            swap(b, d);
        num[i] = a;
        num[i + n] = c;
        e[i] = edge(a, c, b, 1);
        e[i + n] = edge(a, c, d, -1);
    }
    n <<= 1;
    sort(num + 1, num + n + 1);
    cnt = unique(num + 1, num + n + 1) - num - 1;
    sort(e + 1, e + n + 1, cmp);
    for (int i = 1; i < n; ++i) {
        ql = e[i].l;
        qr = e[i].r;
        k = e[i].flag;
        //printf("addval %d times\n", i);
        addval(1, 1, cnt - 1 );
        //printf("%lld %lld\n", tree[1].sum1, tree[1].sum2);
        sum1 += (tree[1].sum1 * (e[i + 1].h - e[i].h));
        sum2 += (tree[1].sum2 * (e[i + 1].h - e[i].h));
    }
    printf("%lld\n", sum1 - sum2);
    return 0;
}
