//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 1e2 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;
#define FO freopen("out.txt","w",stdout);

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

string tmp, cmp, s;
int T = 1, n, ans = 0, flag = 0;

int main()
{
    // FO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        cin >> tmp;
        for (int i = 1; i <= n; ++i) {
            getline(cin, s);
            while (s == "")
                getline(cin, s);
            stringstream X(s);
            while (getline(X, cmp, ' ')) {
                if (cmp == tmp) {
                    ++ans;
                    break;
                }
            }
        }
        if (flag)
            cout << "\n\n";
        if (ans == 0)
            cout << "Do not find";
        else printf("%d", ans);
        flag = 1;
    }
    return 0;
}