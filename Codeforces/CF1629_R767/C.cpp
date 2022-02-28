//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

int a[maxn], cnt[maxn];
vector<int>ans;
bool pic[maxn];

#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

int iget(int n)
{
    for (int i = 0; i <= n + 1; ++i)
        if (cnt[i] == 0)
            return i;
    return n + 1;
}

int main()
{
    int T = 1, n, cur = 0, flag = 0;
    T = _read();
    while (T--) {
        flag = 0;
        ans.clear();
        n = _read();
        for (int i = 1; i <= n; ++i) {
            a[i] = _read();
            cnt[a[i]]++;
        }
        cur = iget(n);
        for (int i = 1; i <= n; ++i) {
            --cnt[a[i]];
            if (!pic[a[i]] && a[i] <= cur) {
                flag++;
                pic[a[i]] = 1;
            }
            if (cur == 0) {
                ans.push_back(0);
                continue;
            }
            if (flag == cur) {
                ans.push_back(cur);
                for (int j = 0; j <= cur; ++j)
                    pic[j] = 0;
                cur = iget(n);
                flag = 0;
            }
        }
        printf("%ld\n", ans.size());
        for (int it = 0; it < ans.size(); ++it)
            printf("%d%c", ans[it], it == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}