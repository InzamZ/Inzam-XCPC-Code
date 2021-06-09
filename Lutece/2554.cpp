#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
using ull = unsigned long long;
#define lo (2*o)
#define ro (2*o+1)

map<ull, int>s;
ull a[maxn], bas[maxn];
ull ans = 0, temp, k;
int beg[maxn], op[maxn], t[maxn], cnt[maxn];
int cnts = 1;
vector<ull>num[maxn];

int n, m, qr, ql, rt = 1;

struct node {
    ull d[65];
    vector<ull>q;
} tree[maxn * 4];

void pushdown(int o)
{
    for (int i = 63; i >= 0; --i)
        tree[lo].d[i] = tree[ro].d[i] = tree[o].d[i];
}

void updateD(int o, ull val)
{
    temp = 1;
    for (int i = 63; i >= 0; --i) {
        if (val & (temp << i)) {
            if (!tree[o].d[i]) {
                tree[o].d[i] = val;
                break;
            }
            else
                val ^= tree[o].d[i];
        }
    }
}
void addval(int o, int L, int R)
{
    if (ql <= L && R <= qr) {
        tree[o].q.push_back(k);
        return ;
    }
    int M = (L + R) / 2;
    if ( M >= ql )
        addval(lo, L, M);
    if ( qr > M )
        addval(ro, M + 1, R);
}
void print(int o)
{
    temp = 0;
    for (int i = 63; i >= 0; --i) {
        if ((temp ^ tree[o].d[i]) > temp)
            temp ^= tree[o].d[i];
    }
    printf("%llu\n", temp);
}
void dfs(int o, int L, int R)
{
    for (int i = 0; i < tree[o].q.size(); ++i)
        updateD(o, tree[o].q[i]);
    if (L == R) {
        print(o);
        return ;
    }
    pushdown(o);
    int M = (L + R) >> 1;
    dfs(lo, L, M);
    dfs(ro, M + 1, R);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %llu", &op[i], &a[i]);
        if (op[i] == 0) {
            if (s.count(a[i]) == 0)
                s[a[i]] = cnts++;
            if (beg[s[a[i]]] == 0)
                beg[s[a[i]]] = i;
            cnt[s[a[i]]]++;
        }
        else {
            if (cnt[s[a[i]]] > 1)
                cnt[s[a[i]]]--;
            else {
                ql = beg[s[a[i]]]; qr = i - 1; k = a[i];
                addval(1, 1, n );
                cnt[s[a[i]]] = 0; beg[s[a[i]]] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (beg[s[a[i]]] != 0) {
            ql = beg[s[a[i]]]; qr = n; k = a[i];
            addval(1, 1, n);
        }
    }
    dfs(1, 1, n);
    return 0;
}
