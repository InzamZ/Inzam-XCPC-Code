#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
using ll = long long;

int ranger[maxn], rangel[maxn], block[maxn];
int cnt[maxn], cnt2[maxn];
ll ans[maxn];

int num[maxn], id[maxn], numuni[maxn];
int unitot = 0;

struct query {
    int l, r, id;
} q[maxn];

bool cmp(query a, query b)
{
    return (block[a.l] ^ block[b.l]) ? block[a.l] < block[b.l] : a.r < b.r;
}

int main()
{
    int N, Q;
    scanf("%d", &N);
    int sqn = sqrt(N);
    int blockn = ceil((double) N / sqn);
    for (int i = 1; i <= blockn; ++i) {
        ranger[i] = sqn * i;
        rangel[i] = sqn * (i - 1) + 1;
        for (int j = rangel[i]; j <= ranger[i]; ++j)
            block[j] = i;
    }
    ranger[blockn] = N;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &num[i]);
        numuni[i] = num[i];
    }
    sort(numuni + 1, numuni + 1 + N);
    unitot = unique(numuni + 1, numuni + 1 + N) - numuni - 1;
    for (int i = 1; i <= N; ++i)
        id[i] = lower_bound(numuni + 1, numuni + 1 + unitot, num[i]) - numuni;
    scanf("%d", &Q);
    for (int i = 1; i <= Q; ++i) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + 1 + Q, cmp);
    int i = 1;
    for (int k = 0; k <= blockn; ++k) {
        int l = ranger[k] + 1, r = ranger[k];
        memset(cnt, 0, sizeof(cnt));
        ll temp = 0, now = 0;
        for (; block[q[i].l] == k; ++i) {
            int ql = q[i].l, qr = q[i].r;
            if (block[q[i].l] == block[q[i].r]) {
                temp = 0;
                for (int j = ql; j <= qr; ++j)
                    cnt2[id[j]] = 0;
                for (int j = ql; j <= qr; ++j) {
                    if (!cnt2[id[j]])
                        cnt2[id[j]] = j;
                    else
                        temp = max(temp, 1ll * (j - cnt2[id[j]]));
                }
                ans[q[i].id] = temp;
                continue;
            }
            while (r < qr) {
                if (!cnt[id[r]])
                    cnt[id[++r]] = r;
                else
                    now = max(now, 1ll * (r - cnt[id[r]]));
            }
            temp = now;
            while (ql < l) {
                if (!cnt[id[--l]])
                    cnt[id[l]] = l;
                else
                    temp = max(temp, 1ll * abs(l - cnt[id[l]]));
            }
            ans[q[i].id] = temp;
            while (l < ranger[k] + 1)
                if (cnt[id[l]] < ranger[k] + 1)
                    cnt[id[l++]] = 0;
                else ++l;
        }
    }
    for (int i = 1; i <= Q; ++i)
        printf("%lld\n", ans[i]);
    return 0;
}