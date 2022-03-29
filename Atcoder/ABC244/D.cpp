//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;
char a[5][5], b[5][5];
int main()
{
    // FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        scanf("%s", a[0]);
        scanf("%s", a[1]);
        scanf("%s", a[2]);
        scanf("%s", b[0]);
        scanf("%s", b[1]);
        scanf("%s", b[2]);
        for (int i = 0; i < 3; i++) {
            if (a[i][0] != b[i][0])
                ans++;
        }
        if (ans == 0 ) cout<< "Yes\n";
        else if (ans == 2) cout<< "No\n";
        else cout<< "Yes\n";
    }
    return 0;
}