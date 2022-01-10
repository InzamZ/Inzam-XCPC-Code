//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 100 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag[maxn];
int T = 1, n, m, ans = 0;
double a[maxn];
vector<double>q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 1e6;
        if (n == 1) ans = 0;
        q.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                q.push_back((a[j] - a[i]) / (j - i));
            }
        }
        sort(q.begin(), q.end());
        int len = unique(q.begin(), q.end()) - q.begin();
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j <= n; ++j) {
                int cnt = 0;
                if (!flag[j]) {
                    for (int k = 1; k <= n; ++k) {
                        if (a[k] != a[j] + (k - j)*q[i]) ++cnt;
                        else flag[k] = 1;
                    }
                    ans = min(ans, cnt);
                }
            }
            for (int k = 1; k <= n; ++k) flag[k] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}