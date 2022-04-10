#include<bits/stdc++.h>
using namespace std;

#define FREAD 1
#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

#define REP(i,a,n) for(int i = (a); i < (n); ++i)

int main()
{
    int n = read(), m = read(), x = read();
    REP(i, 1, n)v[i] = read();
    REP(i, 1, m)E[i].l = read(), E[i].r = read(), E[i].id = i;
    sort(E + 1, E + 1 + m);
    int rmax = 0, pp = 0;
    REP(i, 1, n) {
        rmax = max(rmax, M[v[i] ^ x]);
        while (pp + 1 <= m && E[pp + 1].r <= i) {
            if (E[pp + 1].l <= rmax)
                ans[E[pp + 1].id] = 1;
            pp++;
        }
        M[v[i]] = i;
    }
    REP(i, 1, m)if (ans[i] == 1)printf("yes\n"); else printf("no\n");
    return 0;
}