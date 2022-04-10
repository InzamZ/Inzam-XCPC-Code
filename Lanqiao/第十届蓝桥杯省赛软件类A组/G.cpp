#include<bits/stdc++.h>
using namespace std;
#define LL long long

int n, m, t, ans = 0;
vector<int>s[100010];
int main()
{
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= m; ++i) {
        int ts, id;
        scanf("%d %d", &ts, &id);
        s[id].push_back(ts);
    }
    for (int i = 1; i <= n; ++i) {
        int tmp = 0, lst = 0;
        bool ok = 0;
        if (s[i].size())
            sort(s[i].begin(), s[i].end());
        for (int j = 0; j < s[i].size(); ++j) {
            if (lst == s[i][j]) {
                tmp += 2;
                if (tmp > 5)
                    ok = 1;
            }
            else {
                tmp = max(0, tmp - (s[i][j] - lst - 1));
                if (tmp <= 3)
                    ok = 0;
                tmp += 2;
                if (tmp > 5)
                    ok = 1;
                lst = s[i][j];
            }
        }
        if (s[i][s[i].size() - 1] != t) {
            tmp = max(0, tmp - (t - lst));
            if (ok && tmp > 3)
                ok = 1;
            else
                ok = 0;
        }
        if (ok)
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}