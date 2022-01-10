//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n, m, ans = 0;
string s;
vector<string>q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        q.clear();
        cin >> n;
        cin >> s;
        int cnt = 0;
        string a = "", b = "";
        for (int i = 0; i < n; ++i) {
            a += s[i];
            b = s[i] + b;
            q.push_back(a + b);
        }
        sort(q.begin(), q.end());
        cout << q[0] << '\n';
    }
    return 0;
}