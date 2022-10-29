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
int T = 1, r, c, p, s, a[maxn], b[maxn];
string str[105], tp;
vector<char>cr;
vector<pii>ans;
char ch;
bool fg = 0;
map<char, pii>mp1, mp2;

int solve() {
    cin >> p >> s;
    scanf("%d,%d", &r, &c);
    cin >> tp;
    for (int i = 1; i <= p; ++i) {
        getline(cin, str[i]);
        if (str[i] == "")
            getline(cin, str[i]);
    }
    while ((ch = getchar()) != EOF) {
        if (ch == '<')
            fg = 1;
        else if (ch == '>' && fg)
            fg = 0;
        else if (!fg && ch != '\n')
            cr.push_back(ch);
    }
    cr.resize(r * c);
    for (int i = 0; i < cr.size(); ++i) {
        if (mp1.count(cr[i]) == 0) {
            mp1[cr[i]] = {i / c + 1, i % c + 1};
        }
        mp2[cr[i]] = {i / c + 1, i % c + 1};
    }
    for (int i = 1; i <= p; ++i) {
        fg = 1;
        ans.clear();
        for (int j = 0; j < str[i].length(); ++j) {
            if (mp1.count(str[i][j]) == 0) {
                fg = 0;
                break;
            }
            if (tp == "S")
                ans.push_back(mp1[str[i][j]]);
            else
                ans.push_back(mp2[str[i][j]]);
        }
        if (fg) {
            for (int i = 0; i < ans.size(); ++i) {
                if (i != 0)
                    cout << ',';
                cout << ans[i].first << ',' << ans[i].second ;
            }
            cout << '\n';
        }
        else
            cout << "0\n";
    }
    return 0;
}

signed main() {
    // FIO;
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}