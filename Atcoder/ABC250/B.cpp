//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 1e3 + 10;
const int maxb = 110;
int T = 1, n, m, x, a, b, ans = 0;
int imap[maxn][maxn];
signed main()
{
    FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> a >> b;
        forr(i, 0, n) {
            bool ok = i % 2;
            forr(j, 0, n) {
                forr(k, 0, a) {
                    forr(l, 0, b) {
                        imap[i * a + k][j * b + l] = ok;
                    }
                }
                ok = !ok;
            }
        }
        forr(i,0,n*a) {
            forr(j,0,n*b) {
                if (imap[i][j])
                    cout << '#';
                else
                    cout << '.';
            }
            cout << '\n';
        }
    }
    return 0;
}