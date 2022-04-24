//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e6 + 10;
int T = 1, n, ans = 0, m;
string mp[110], mp2[110];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> mp[i];
            mp[i] = " " + mp[i];
            mp2[i] = mp[i];
            for (int j = 1; j <= m; ++j)
                mp2[i][j] = '.';
        }
        for (int i = 1; i <= m; ++i) {
            int o = n, cnt = 0;
            for (int j = n; j > 0; --j) {
                if (mp[j][i] == 'o') {
                    for (int k = 0; k < cnt; ++k)
                        mp2[o - k][i] = '*';
                    cnt = 0;
                    o = j - 1;
                    mp2[j][i] = 'o';
                }
                else if (mp[j][i] == '*')
                    cnt++;
            }
            for (int k = 0; k < cnt; ++k)
                mp2[o - k][i] = '*';
        }
        for (int i = 1; i <= n; ++i) {
            cout << mp2[i].substr(1, m);
            cout << '\n';
        }
    }
    return 0;
}