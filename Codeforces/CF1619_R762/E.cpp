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

#ifdef FREAD
static char buf[1000000], *p1 = buf, *p2 = buf, obuf[1000000], *p3 = obuf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
template<typename item>
inline void read(register item &x)
{
    x = 0; register int f = 1; register char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    x *= f;
}
#endif

int T = 1, n, x;
ll res = 0, cnt[maxn];

priority_queue<int>q;

int main()
{
    read(T);
    while (T--) {
        res = 0;
        while (!q.empty())
            q.pop();
        read(n);
        for (int i = 1; i <= n; ++i) {
            read(x);
            ++cnt[x];
        }
        for (int i = 1; i <= n; ++i)
            cnt[i] += cnt[i - 1];
        bool flag = 1;
        for (int i = 0; i <= n; ++i) {
            // printf("000000\n");
            if (flag == 0)
                printf("-1");
            else if (cnt[i] == i) {
                if (i != 0)
                    printf("%lld", cnt[i] - cnt[i - 1] + res);
                else
                    printf("%lld", cnt[i] + res);
            }
            else {
                if (i != 0)
                    printf("%lld", cnt[i] - cnt[i - 1] + res);
                else
                    printf("%lld", cnt[i] + res);
            }
            if (i == 0 && cnt[i] == 0)
                flag = 0;
            else if (i > 0 && cnt[i] - cnt[i - 1] == 0) {
                if (!q.empty()) {
                    res += (i - q.top());
                    q.pop();
                }
                else
                    flag = 0;
            }
            else if (i == 0 && cnt[i] > 1) {
                for (int j = 2; j <= cnt[i]; ++j)
                    q.push(0);
            }
            else if (i != 0 && cnt[i] - cnt[i - 1] > 1) {
                for (int j = 2; j <= cnt[i] - cnt[i - 1]; ++j)
                    q.push(i);
            }
            putchar(' ');
        }
        putchar('\n');
        for (int i = 0; i <= n; ++i)
            cnt[i] = 0;
    }
    return 0;
}