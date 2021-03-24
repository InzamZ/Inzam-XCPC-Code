#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

#define MAXN 1000005
#define MAXB 2000005

char str[MAXN], s[2 * MAXN];
ll lazy[8 * MAXN], mx[8 * MAXN], mn[MAXN * 8];
ll n, cur = 1000000, qr, ql, k;

#define lo 2 * o
#define ro 2 * o + 1

void add(int u, int v)
{
    mx[u] += v;
    mn[u] += v;
    lazy[u] += v;
}

void pushdown(ll o, ll L, ll R)
{
    if (lazy[o] == 0)
        return;
    add(lo, lazy[o]);
    add(ro, lazy[o]);
    lazy[o] = 0;
}

void addval(ll o, ll L, ll R)
{
    if (ql <= L && R <= qr)
    {
        add(o, k);
        return;
    }
    pushdown(o, L, R);
    ll M = (L + R) / 2;
    if (M >= qr)
        addval(lo, L, M);
    else if (ql > M)
        addval(ro, M + 1, R);
    else
    {
        addval(lo, L, M);
        addval(ro, M + 1, R);
    }
    mx[o] = max(mx[lo], mx[ro]);
    mn[o] = min(mn[lo], mn[ro]);
}

ll qmin(ll o, ll L, ll R)
{
    if (ql <= L && R <= qr)
        return mn[o];
    pushdown(o, L, R);
    ll M = (L + R) >> 1;
    if (ql > M)
        return qmin(ro, M + 1, R);
    else if (qr <= M)
        return qmin(lo, L, M);
    else
        return min(qmin(ro, M + 1, R), qmin(lo, L, M));
}

int main()
{
    scanf("%lld", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'L')
            cur--;
        else if (str[i] == 'R')
            cur++;
        else if (str[i] == '(')
        {
            ql = cur;
            qr = MAXB;
            if (s[cur] == ')')
            {
                k = 2;
                addval(1, 1, MAXB);
            }
            else if (s[cur] != '(')
            {
                k = 1;
                addval(1, 1, MAXB);
            }
            s[cur] = str[i];
        }
        else if (str[i] == ')')
        {
            ql = cur;
            qr = MAXB;
            if (s[cur] == '(')
            {
                k = -2;
                addval(1, 1, MAXB);
            }
            else if (s[cur] != ')')
            {
                k = -1;
                addval(1, 1, MAXB);
            }
            s[cur] = str[i];
        }
        else
        {
            ql = cur;
            qr = MAXB;
            if (s[cur] == '(')
            {
                k = -1;
                addval(1, 1, MAXB);
            }
            else if (s[cur] == ')')
            {
                k = 1;
                addval(1, 1, MAXB);
            }
            s[cur] = str[i];
        }
        //for (int i=1;i<=100;i++){printf("i=%d %lld %lld %lld\n",i,mx[i],mn[i],lazy[i]);}
        ql = MAXB - 1, qr = MAXB;
        if (mn[1] >= 0 && qmin(1, 1, MAXB) == 0)
            printf("%lld%c", mx[1], i == n - 1 ? '\n' : ' ');
        else
            printf("-1%c", i == n - 1 ? '\n' : ' ');
    }
    return 0;
}