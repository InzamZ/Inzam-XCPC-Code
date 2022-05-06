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
struct node {
    int id, val;
    bool operator < (const node &rhs) const
    {
        if (val != rhs.val)
            return val < rhs.val;
        return id < rhs.id;
    }
} no[maxn];
bool vis[maxn];
int a[maxn], odds[maxn], evens[maxn];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            no[i].id = i;
            no[i].val = a[i];
        }
        sort(no + 1, no + n + 1);
        for (int i = 1; i <= n; ++i) {
            if (no[i].val < 0 || vis[no[i].id])
                continue;
            int id = no[i].id, l = id - 1, r = id + 1;
            int cntpos = 1, cntneg = 0, sum = no[i].val;
            while (1) {
                if (vis[l] && vis[r])
                    break;
                else if (!vis[l] && vis[r]) {
                    if (sum + a[l] >= 0) {
                        sum += a[l];
                        vis[l] = true;
                        if (a[l] > 0)
                            cntpos++;
                        if (a[l] < 0)
                            cntneg++;
                    }
                    else
                        break;
                }
                else if (!vis[r] && vis[l]) {
                    if (sum + a[r] >= 0) {
                        sum += a[r];
                        vis[r] = true;
                        if (a[r] > 0)
                            cntpos++;
                        if (a[r] < 0)
                            cntneg++;
                    }
                    else
                        break;
                }
                else {
                    int ch = a[l] > a[r] ? l : r;
                    if (sum + a[ch] >= 0) {
                        sum += a[ch];
                        vis[ch] = true;
                        if (a[ch] > 0)
                            cntpos++;
                        if (a[ch] < 0)
                            cntneg++;
                    }
                    else
                        break;
                }
            }
            if (sum == 0){
                int ch = a[l + 1] < a[r - 1] ? l + 1 : r - 1;

                }


        }
        cout << ans << '\n';
    }
    return 0;
}