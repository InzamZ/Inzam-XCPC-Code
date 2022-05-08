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
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0;
int a[maxn], pos[maxn];
signed main()
{
    FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        forr(i, 1, n + 1) {
            a[i] = i;
            pos[i] = i;
        }
        forr(i, 0, m) {
            cin >> x;
            if (pos[x] != n) {
                swap(a[pos[x]], a[pos[x] + 1]);
                pos[a[pos[x]]] = pos[x];
                pos[a[pos[x] + 1]] = pos[x] + 1;
            }
            else {
                swap(a[pos[x]], a[pos[x] - 1]);
                pos[a[pos[x]]] = pos[x];
                pos[a[pos[x] - 1]] = pos[x] - 1;
            }
        }
        forr(i, 1, n + 1) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}