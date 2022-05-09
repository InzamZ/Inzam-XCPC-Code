//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 1e6 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0;
int row[maxn], col[maxn];
string s;

signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m >> s;
        forr(i, 1, n * m)
        {
            x = s[i - 1] - '0';
            if (x == 1 && col[(i - 1) % m + 1] == 0)
            {
                col[(i - 1) % m + 1] = 1;
                col[0]++; 
            }
            if (x == 1)
            {
                if (i <= m) {
                    row[0] += 1;
                    row[i] = 1;
                }
                else {
                    if (s[i - m - 1] == '0') row[0]++;
                    if (row[0]) row[i] = row[i - m] + 1;
                    else row[i] = row[i - m];
                }
            }
            else 
            {
                if (i <= m) row[i] = (row[0] > 0) ;
                else {
                    if (s[i - 1 - m] == '1') --row[0];
                    if (row[0]) row[i] = row[i - m] + 1;
                    else row[i] = row[i - m];
                } 
            }
            cout << col[0] + row[i] << ' '; 
        }
        forr(i, 0, max(m, n)) row[i] = col[i] = 0;
        cout << '\n';
    }
    return 0;
}