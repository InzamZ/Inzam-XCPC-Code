//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        string s1, s2;
        int cnt[30], cnt2[30];
        for (int i = 0; i < 30; i++)
            cnt[i] = cnt2[i] = 0;
        cin >> s1 >> s2;
        for (int i = 0; i < s2.size(); i++) {
            cnt[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i])
                cout << 'g';
            else {
                if (cnt[s1[i] - 'a'] > cnt2[s1[i] - 'a'])
                    cout << 'x';
                else
                    cout << 'y';
            }
        }
        cout << '\n';
    }
    return 0;
}