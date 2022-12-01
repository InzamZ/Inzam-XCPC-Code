#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 70;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int rmx, cnt, lmx, r, c;
char s[maxn];
int imap[maxn][maxn];

int main()
{
    int T = 1, n, ans = 0;
    scanf("%d", &T);
    while (T--) {
        bool flag = true;
        memset(imap, 0, sizeof(imap));
        rmx = lmx = 0;
        scanf("%d %d", &r, &c);
        for (int i = 1; i <= r; ++i) {
            scanf("%s", s);
            for (int j = 0; j < c; ++j) {
                imap[i][j + 1] = s[j] == 'A';
                if (!imap[i][j + 1])
                    flag = false;
                if (imap[i][j + 1])
                    imap[0][j + 1]++;
                if (imap[i][j + 1])
                    imap[i][0]++;
                rmx = max (rmx, imap[i][0]);
                lmx = max(lmx, imap[0][j + 1]);
            }
        }
        if (flag)
            printf("0\n");
        else if (imap[0][1] == r || imap[0][c] == r || imap[1][0] == c || imap[r][0] == c)
            printf("1\n");
        else if (lmx == r || rmx == c || imap[1][1] || imap[1][c] || imap[r][1] || imap[r][c])
            printf("2\n");
        else if (rmx == 0 && lmx == 0)
            printf("MORTAL\n");
        else if (imap[0][1] || imap[0][c] || imap[1][0] || imap[r][0])
            printf("3\n");
        else
            printf("4\n");
    }
    return 0;
}