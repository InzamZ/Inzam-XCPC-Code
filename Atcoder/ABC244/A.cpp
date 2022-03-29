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
string s;
int main()
{
    FIO;
    while (T--) {
        ans = 0;
        cin >> n;
        cin >> s;
        cout << s[s.length()-1] << '\n';
    }
    return 0;
}