#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll maxn = 1e18 + 7;
const int maxa = 1e5 + 7;
ll fb[100];
int n, j, num[maxa];
ll a[maxa];
int query(ll x, int m, int n)
{
    if (m == 0)
        return n;
    if (x - fb[m] == 0)
        n++;
    if (x - fb[m] != 0)
        x = x - fb[m];
    m = min(m - 1, (int)(upper_bound(fb, fb + j - 1, x) - fb - 1));
    return query(x, m, n);
}
int main()
{
    fb[0] = 0;
    fb[1] = 1;
    fb[2] = 2;
    for (j = 3; j <= 86; j++)
        fb[j] = fb[j - 1] + fb[j - 2];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int m = 1; m <= n; m++) {
        int i = upper_bound(fb, fb + j - 1, a[m]) - fb - 1;
        num[m] = query(a[m], i, 0);
        printf("%d\n", num[m]);
    }
    return 0;
}
