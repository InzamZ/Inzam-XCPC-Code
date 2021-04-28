#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;

ll s[maxn], s2[maxn];

ll mergesort(ll l, ll r)
{
    if (l == r)
        return 0;
    ll cnt = 0, mid = (l + r) >> 1, i = l, j = mid + 1, k = l;
    cnt += mergesort(l, mid);
    cnt += mergesort(mid + 1, r);
    while (i <= mid && j <= r)
    {
        if (s[i] >= s[j])
        {
            cnt += (mid - i + 1);
            s2[k++] = s[j++];
        }
        else
            s2[k++] = s[i++];
    }
    while (i <= mid)
        s2[k++] = s[i++];
    while (j <= r)
        s2[k++] = s[j++];
    for (i = l; i <= r; i++)
        s[i] = s2[i];
    return cnt;
}
ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, sum = 0, ans, gcdnum;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = s[i-1] +s[i] - k ;
    }
    //for (int i=1;i<=n;i++) cout<<s[i]<<endl;
    ans = mergesort(0, n);
    gcdnum = gcd(ans, (n * (n + 1)) / 2ll);
    cout << ans / gcdnum << '/' << n * (n + 1) / 2ll / gcdnum << endl;
    return 0;
}