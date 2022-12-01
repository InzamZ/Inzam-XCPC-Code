#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

vector<pii>v;
int T = 1, n, ans = 0, l, r, mid;
ll s;

bool check(int val)
{
    ll temp = s;
    int cnt1 = 0, cnt2 = 0;
    // if ( v[n / 2].second < val)
    //     return false;
    // if (v[n / 2].first > val )
    //     return true;
    for (int i = 0; i < n ; ++i) {
        if (v[i].first > val) {
            temp -= v[i].first;
            ++cnt1;
        }
    }
    if (cnt1 > n / 2)
        return true;
    for (int i = 0; i < n; ++i) {
        if (v[i].second < val ) {
            temp -= v[i].first;
            ++cnt2;
        }
    }
    if (cnt2 > n / 2)
        return false;
    for (int i = 0; cnt2 < n / 2 && i < n; ++i) {
        if (v[i].first <= val && val <= v[i].second) {
            temp -= v[i].first;
            ++cnt2;
        }
    }
    for (int i = 0; cnt1 < n / 2 && i < n; ++i) {
        if (v[i].first <= val && val <= v[i].second) {
            temp -= val;
            ++cnt1;
        }
    }
    return temp - val >= 0;
}

// bool cmp(pii a, pii b)
// {
//     return a.second < b.second;
// }

int main()
{
    scanf("%d", &T);
    while (T--) {
        v.clear();
        scanf("%d %lld", &n, &s);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &l, &r);
            v.push_back(pii{l, r});
        }
        sort(v.begin(), v.end());
        l = 1; r = 1e9 + 1;
        while (l + 1 < r) {
            mid = (l + r) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}