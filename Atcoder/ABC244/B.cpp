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
int T = 1, n, ans = 0, dir = 0;
int x = 0, y = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
string s;
int main()
{
    FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R')
                dir = (dir + 1) % 4;
            else {
                x += dx[dir];
                y += dy[dir];
            }
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}