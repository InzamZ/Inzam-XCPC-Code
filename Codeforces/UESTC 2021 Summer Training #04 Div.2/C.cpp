#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;

ll a[maxn], cost = 0;

priority_queue<ll, vector<ll>, greater <ll> > q;

int main()
{
    int  n, lgn = 0;
    ll cnt = 0, s, k;
    cnt = cost = 0;
    bool flag = 1;
    scanf("%d", &n);
    while ((1 << lgn) != n)
        ++lgn;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if (a[i] == -1)
            flag = false;
        if (a[i] != -1 && flag)
            cnt++;
    }
    flag = false;
    if (cnt == n - 1 )
        cost = 0;
    else if (cnt >= (1 << (lgn - 1)) - 1)
        cost = a[n];
    else {
        cost = a[n];
        int t = (1 << (lgn - 1)), cur = n;
        while (t) {
            for (int i = 1; !flag && i <= t; ++i) {
                q.push(a[--cur]);
                if (a[cur] == -1) {
                    flag = true;
                    break;
                }
            }
            t /= 2;
            if (flag)
                break;
            else {
                cost += q.top();
                q.pop();
            }
        }
    }
    printf("%lld\n", cost);
    return 0;
}