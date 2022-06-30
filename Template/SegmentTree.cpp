#include<cstdio>
#include<iostream>
using namespace std;

#define maxn 100010
typedef long long ll;
ll num[100010], k, ans;

class SegmentTree {

#define lo (tree[o].son[0])
#define ro (tree[o].son[1])
#define len(a,b) ((b)-(a)+1)

  public:

    int tot = 0;
    struct node {
        int val, lazy;
        int son[2];
    } tree[maxn * 4];

    SegmentTree(int siz) {
        tot = 0;
        build(1, 1, siz);
    }

    void pushup(int o) {
        tree[o].val = tree[lo].val + tree[ro].val;
    }

    void pushdown(int o, int L, int R) {
        int M = (L + R) / 2;
        tree[lo].lazy += tree[o].lazy;
        tree[ro].lazy += tree[o].lazy;
        tree[lo].val += len(L, M) * tree[o].lazy;
        tree[ro].val += len(M + 1, R) * tree[o].lazy;
        tree[o].lazy = 0;
    }

    void build(int o, int L, int R) {
        tree[o].lazy = 0;
        if (L == R) {
            tree[o].val = num[L];
            return ;
        }
        int M = (L + R) / 2;
        tree[o].son[0] = ++tot;
        build(lo, L, M);
        tree[o].son[1] = ++tot;
        build(ro, M + 1, R);
        pushup(o);
    }

    int getsum(int o, int L, int R, int ql, int qr) {
        int res = 0;
        if (ql <= L && R <= qr)
            return tree[o].val;
        pushdown(o, L, R);
        int M = (L + R) / 2;
        if ( M >= ql)
            res += getsum(lo, L, M, ql, qr);
        if ( M < qr )
            res += getsum(ro, M + 1, R, ql, qr);
        return res;
    }

    void addval(int o, int L, int R, int ql, int qr) {
        if (ql <= L && R <= qr) {
            tree[o].val += k * len(L, R);
            tree[o].lazy += k;
            return ;
        }
        pushdown(o, L, R);
        int M = (L + R) / 2;
        if ( M >= ql )
            addval(lo, L, M, ql, qr);
        if ( qr > M )
            addval(ro, M + 1, R, ql, qr);
        tree[o].val = tree[lo].val + tree[ro].val;
    }
};