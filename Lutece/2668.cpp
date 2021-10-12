//InzamZ
//
#pragma GCC diagnostic error "-std=c++17"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define REG register
#define FREAD 1

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
// const ll mod = 1e9+7;

//a*b % mod
inline ll mul_mod(ll a, ll b, ll mod)//防爆快速乘
{
    ll c = a * b - (ll)((long double)a * b / mod + 0.5) * mod;
    return c < 0 ? c + mod : c;
}

//快速幂 a^x % mod
inline ll qpow(ll a, ll x, ll mod)
{
    ll ans = 1;
    while (x) {
        if (x & 1ll)
            ans = mul_mod(ans, a, mod);
        a = mul_mod(a, a, mod);
        x >>= 1;
    }
    return ans;
}

//探测底数a , 检验n是否为质数
inline bool detect(ll n, ll a)
{
    if (n == a)
        return true;
    else if (!(a % n))
        return true;
    ll p = n - 1, lst = 1;
    if (qpow(a, p, n) != 1)
        return false;
    while (!(p & 1ll)) {
        p /= 2;
        ll res = qpow(a, p, n);
        if (lst == 1 && res != 1 && res != n - 1)
            return false;
        lst = res;
    }
    return 1;
}
ll p[10] = {2,3,5,7,11,13,17,19,23,29};
//MR算法
//3e18内 ll p[10] = {2,3,5,7,11,13,17,19,23,29};
//int64 ll p[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
inline bool Miller_Robin(ll n)
{
    if (n < 2)
        return false;
    if (n < 2)
        return false;
    if (!detect(n, p[0]))
        return false;
    if (!detect(n, p[1]))
        return false;
    if (!detect(n, p[2]))
        return false;
    if (!detect(n, p[3]))
        return false;
    if (!detect(n, p[4]))
        return false;
    if (!detect(n, p[5]))
        return false;
    if (!detect(n, p[6]))
        return false;
    if (!detect(n, p[7]))
        return false;
    if (!detect(n, p[8]))
        return false;
    if (!detect(n, p[9]))
        return false;
    return true;
}

inline ll gcd(ll a, ll b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    register int t = __builtin_ctzll(a | b) ;
    a >>= __builtin_ctzll(a) ;
    do {
        b >>= __builtin_ctzll(b) ;
        if (a > b) {
            ll t = b;
            b = a, a = t;
        }
        b -= a;
    }
    while (b);
    return a << t;
}

inline ll F(ll x, ll c, ll mod)
{
    return (mul_mod(x, x, mod) + c) % mod;
}

inline ll Rand()
{
    return rand() << 15 ^ rand();
}

inline ll LLRand()
{
    return 1ll * ((rand() << 15 ^ rand()) << 30 ^ (rand() << 15 ^ rand())) ;
}

inline ll Pollard_Rho(ll n)
{
    if (n == 4)
        return 2;
    if (Miller_Robin(n))
        return n;
    while (true) {
        ll c = LLRand() % (n - 1) + 1;
        ll s = 0, t = 0, acc = 1;
        do {
            ll c = LLRand() % (n - 1) + 1, temp;
            for (REG int i = 0; i < 128; ++i) {
                t = F(F(t, c, n), c, n);
                s = F(s, c, n);
                temp = mul_mod(acc, abs(t - s), n);
                if (s == t || !temp)
                    break;
                acc = temp;
            }
            ll ngcd = gcd(n, acc);
            if (ngcd > 1)
                return ngcd;
        }
        while (s != t);
    }
}

inline vector<pli> DCOMP(ll n)
{
    vector<pli> ans;
    while (n != 1) {
        ll p = Pollard_Rho(n);
        while (!Miller_Robin(p))
            p = Pollard_Rho(p);
        int cnt = 0;
        while (n % p == 0)
            n /= p, ++cnt;
        if (p % 4 == 1)
            ans.push_back(pli(p, cnt));
    }
    return ans;
}

#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll _read()
{
    char ch = nc(); ll sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

int main()
{
    srand(time(0));
    int T = 1;
    ll ans = 0, n;
    T = _read();
    while (T--) {
        ans = 4;
        n = _read();
        auto v = DCOMP(n);
        for (int i = 0; i < v.size(); ++i)
            ans *= (2 * v[i].second + 1);
        printf("%lld\n", ans);
    }
    return 0;
}