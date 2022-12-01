namespace Pollard_Rho
{
using namespace NT;
using namespace Miller_Rabin;
LL f(LL x, LL C, LL p)
{
    return (mul(x, x, p) + C) % p;
}
LL Rand()
{
    return (rand() << 15) + rand();
}
LL Randll()
{
    return (Rand() << 31) + Rand();
}
LL PR(LL n)
{
    if (n == 4)
        return 2;
    if (MR(n))
        return n;
    while (1) {
        LL C = Randll() % (n - 1) + 1;
        LL s = 0, t = 0;
        LL acc = 1;
        do {
            for (int i = 1; i <= 128; ++i) {
                t = f(f(t, C, n), C, n);
                s = f(s, C, n);
                LL tmp = mul(acc, abs(t - s), n);
                if (s == t || tmp == 0)
                    break;
                acc = tmp;
            }
            LL d = gcd(n, acc);
            if (d > 1)
                return d;
        }
        while (s != t);
    }
}
typedef pair<LL, int > pii;
vector<pii > DCOMP(LL n)
{
    vector<pii > ret;
    while (n != 1) {
        LL p = PR(n);
        while (!MR(p))
            p = PR(p);
        int c = 0;
        while (n % p == 0)
            n /= p, ++c;
        ret.push_back(make_pair(p, c));
    }
    return ret;
}
}