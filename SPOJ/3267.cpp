#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 1000010

int block[maxn], rangel[maxn], ranger[maxn];
int num[maxn], cnt[maxn], ans[maxn], now = 0;

struct query {
    int l, r, id;
} q[maxn];

bool cmp(query a, query b)
{
    return (block[a.l] ^ block[b.l]) ? block[a.l] < block[b.l] : (block[a.l] & 1) ? a.r<b.r: a.r>b.r;
}

void add(int k)
{
    if (!cnt[k])
        ++now;
    ++cnt[k];
}

void del(int k)
{
    --cnt[k];
    if (!cnt[k])
        --now;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    int sqn = sqrt(n), blockn = ceil(n / sqrt(n));
    for (int i = 1; i <= blockn; ++i) {
        rangel[i] = sqn * (i - 1) + 1;
        ranger[i] = sqn * i;
        for (int j = sqn * (i - 1) + 1; j <= sqn * i; ++j)
            block[j] = i;
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &num[i]);
    scanf ("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; ++i) {
        int ql = q[i].l, qr = q[i].r;
        while (ql < l)
            add(num[--l]);
        while (r < qr)
            add(num[++r]);
        while (l < ql)
            del(num[l++]);
        while (qr < r)
            del(num[r--]);
        ans[q[i].id] = now;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", ans[i]);
    return 0;
}