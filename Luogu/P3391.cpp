#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 100010
int n, m;
struct spt {
    int root;
    int s[N], ch[N][2], f[N], mark[N];
    void clean()
    {
        root = 0;
        memset(s, 0, sizeof(s));
        memset(ch, 0, sizeof(ch));
        memset(mark, 0, sizeof(mark));
    }
    void build(int L, int R, int &rt)
    {
        if (L > R)
            return ;
        int mid = (L + R) / 2;
        if (mid < rt)
            ch[rt][0] = mid;
        else
            ch[rt][1] = mid;
        f[mid] = rt;
        s[mid] = 1;
        if (L == R)
            return ;
        build(L, mid - 1, mid);
        build(mid + 1, R, mid);
        s[mid] = s[ch[mid][0]] + s[ch[mid][1]] + 1;
    }
    void pd(int &rt)
    {
        if (mark[rt]) {
            int &r = ch[rt][1], &l = ch[rt][0];
            swap(r, l);
            mark[l] ^= 1;
            mark[r] ^= 1;
            mark[rt] = 0;
        }
    }
    void rotate(int x, int &k)
    {
        int y = f[x], z = f[y], d = ch[y][1] == x;
        if (y == k)
            k = x;
        else
            ch[z][ch[z][1] == y] = x;
        f[ch[x][d ^ 1]] = y;
        f[y] = x;
        f[x] = z;
        ch[y][d] = ch[x][d ^ 1];
        ch[x][d ^ 1] = y;
        s[x] = s[ch[x][0]] + s[ch[x][1]] + 1;
        s[y] = s[ch[y][0]] + s[ch[y][1]] + 1;
    }
    void splay(int x, int &k)
    {
        while (x != k) {
            int y = f[x], z = f[y];
            if (y != k) {
                if ((ch[z][0] == y) ^ (ch[y][0] == x))
                    rotate(x, k);
                else
                    rotate(y, k);
            }
            rotate(x, k);
        }
    }
    int serect(int &rt, int k)
    {
        pd(rt);
        if (s[ch[rt][0]] + 1 == k)
            return rt;
        if (s[ch[rt][0]] + 1 > k)
            return serect(ch[rt][0], k);
        else
            return serect(ch[rt][1], k - s[ch[rt][0]] - 1);
    }
    void rever(int L, int R)
    {
        splay(L, root);
        splay(R, ch[L][1]);
        mark[ch[R][0]] ^= 1;
    }
    void print(int &rt)
    {
        pd(rt);
        if (ch[rt][0])
            print(ch[rt][0]);
        if (2 <= rt && rt <= n + 1)
            printf("%d ", rt - 1);
        if (ch[rt][1])
            print(ch[rt][1]);
    }
} T;
int main()
{
    T.clean();
    scanf ("%d %d", &n, &m);
    int &rt = T.root = (3 + n) >> 1;
    T.build(1, n + 2, rt);
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf ("%d %d", &l, &r);
        int ll = T.serect(rt, l), rr = T.serect(rt, r + 2);
        T.rever(ll, rr);
    }
    T.print(rt);
    return 0;
}