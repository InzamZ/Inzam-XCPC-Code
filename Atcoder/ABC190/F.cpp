#include <bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
using ll = long long;
const ll maxn = 3e5 + 10;
vector <ll> a(maxn), b(maxn);
vector <ll> c(maxn);

ll mergesort (ll l, ll r)
{
    if (l == r)
        return 0;
    ll ans = 0;
    ans += mergesort(l, mid);
    ans += mergesort(mid + 1, r);
    ll i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            c[k++] = a[i++];
        else {
            c[k++] = a[j++];
            ans += (mid - i + 1);
        }
    }
    for (i; i <= mid; i++)
        c[k++] = a[i];
    for (j; j <= r; j++)
        c[k++] = a[j];
    for (i = l; i <= r; i++)
        a[i] = c[i];
    return ans;
}

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)     {
        cin >> a[i];
        b[i] = a[i];
    }
    ll ans = mergesort(0, n - 1);
    cout << ans << endl;
    for (int i = 1; i < n; i++) {
        ans += (n - 1 - 2 * b[i - 1]);
        cout << ans << endl;
    }
    return 0;
}