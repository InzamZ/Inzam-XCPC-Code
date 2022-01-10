#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct node {
    ll pos, mark, flag;

    node(ll a, ll b = 4, ll c = 0) : pos(a), mark(b), flag(c) {}
};

ll cnt[10] = {0};
vector<node>s;

struct Mart {
    ll val[3][3];

    Mart ()
    {
        memset(val, 0, sizeof(val));
        for (int i = 0; i < 3; ++i)
            val[i][i] = 0;
    }

    Mart (ll t)
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                if (i == j)
                    val[i][j] = t;
                else
                    val[i][j] = 0;
            }
    }

    Mart operator* (Mart B)
    {
        Mart ans;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    ans.val[i][j] = ans.val[i][j] + (val[i][k] * B.val[k][j]) % mod;
                    ans.val[i][j] %= mod;
                }
            }
        return ans;
    }

    Mart operator = (const Mart B)
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                val[i][j] = B.val[i][j];
        return *this;
    }

};

Mart temp = Mart(1);
Mart qpow(Mart A, ll x)
{
    Mart ans = Mart(1);
    if (x < 0)
        return ans;
    while (x) {
        if (x & 1)
            ans = ans * A;
        x >>= 1;
        A = A * A;
    }
    return ans;
}

bool cmp(node x, node y)
{
    return x.pos < y.pos;
}

void update(Mart &V)
{
    for (int i = 0; i < 3; ++i) {
        if (cnt[i]) {
            for (int j = 0; j < 3; ++j)
                V.val[i][j] = 0;
        }
        else {
            for (int j = 0; j < 3; ++j)
                V.val[i][j] = temp.val[i][j];
        }
    }
}

int main()
{
    ll n, m, a, b, c, ans = 0, pos = 2;
    scanf ("%lld %lld", &n, &m);
    temp.val[0][1] = temp.val[2][1] = temp.val[1][0] = temp.val[1][2] = 1;
    for (int i = 1; i <= m; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        s.push_back(node(a, c, 1));
        s.push_back(node(b + 1, c, 0));
    }
    Mart A = Mart(1), B = temp;
    sort(s.begin(), s.end(), cmp);
    s.end()->pos = n;
    for (auto i = s.begin(); i != s.end();) {
        while (i != s.end() && i->pos == pos) {
            if (i->flag)
                ++cnt[i->mark];
            else  --cnt[i->mark];
            ++i;
        }
        update(B);
        A = A * qpow(B, i->pos - pos);
        pos = i->pos;
    }
    // A = A * qpow(B, n - pos);
    for (int i = 0; i < 3; ++i) {
        ans += A.val[i][1];
        ans %= mod;
    }
    printf("%lld\n", ans % mod);
    return 0;
}