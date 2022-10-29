//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x;
vector<int>e[maxn], v;
char ch, ab[10];
int sig = 1;
bool fg = 0;

int solve() {
    double a = 0, b = 0, ans = 0, adot = 0, res = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '-') {
            a += res;
            sig = -1; adot = fg = res = 0;
        }
        else if (ch == '+') {
            a += res;
            sig = 1; adot = fg = res = 0;
        }
        else if (ch == 'i') {
            if (!fg)
                res = 1;
            b += (sig * res);
            sig = 1; adot = fg = res = 0;
        }
        else if (ch >= '0' && ch <= '9') {
            if (adot) {
                adot /= 10;
                res = res + (ch - '0') * adot;
            }
            else
                res = res * 10 + (ch - '0');
            fg = 1;
        }
        else if (ch == '.') {
            fg = 1;
            adot = 1.0;
        }
        else if (ch == '\n')
            break;
    }
    a += res;
    b = -b;
    ans = sqrt(a * a + b * b);
    if (!a && !b)
        printf("0");
    else if (a) {
        if (b == 1)
            printf("%g+i", a);
        else if (b == -1)
            printf("%g-i", a);
        else if (b > 0)
            printf("%g+%gi", a, b);
        else if (b < 0)
            printf("%g%gi", a, b);
        else
            printf("%g", a);
    }
    else {
        if (a)
            if (b == 1)
                printf("%g+i", a);
            else if (b == -1)
                printf("%g-i", a);
            else if (b > 0)
                printf("%g+%gi", a, b);
            else
                printf("%g%gi", a, b);
        else if (b == 1)
            printf("i");
        else if (b == -1)
            printf("-i");
        else
            printf("%gi", b);
    }
    printf(" %g\n", ans);
    return 0;
}

signed main() {
    cin >> T;
    ch = getchar();
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}