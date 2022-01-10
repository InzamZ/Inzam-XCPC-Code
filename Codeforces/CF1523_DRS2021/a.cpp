#include <bits/stdc++.h>
using namespace std;
#define maxn (1e5+10)
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f
char c[100010];
deque<int>q;

int main()
{
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        while (!q.empty())
            q.pop_front();
        scanf("%d %d", &n, &m);
        scanf("%s", c);
        for (int i = 0; i < n; i++) {
            int l, r;
            if (c[i] == '1') {
                l = max(i - m, 0);
                r = min(i + m, n - 1);
                if (!q.empty() && q.back() >= l) {
                    q.pop_back();
                    q.push_back(r);
                }
                else {
                    q.push_back(l); q.push_back(r);
                }
            }
        }
        int l = q.front(); q.pop_front();
        int r = q.front(); q.pop_front();
        for (int i = 0; i < n; ++i) {
            if (i > r && !q.empty()) {
                l = q.front(); q.pop_front();
                r = q.front(); q.pop_front();
            }
            if (l <= i && i <= r)
                putchar('1');
            else
                putchar('0');
        }
        putchar('\n');
    }
    return 0;
}