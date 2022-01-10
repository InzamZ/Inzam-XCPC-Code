#define AWSL <bits/stdc++.h>
#define awei_sine using namespace std
#define reg register
#define F(i,b,n)  for(reg int i=(b);i<(n);i++)
#define Mai(i,b,n)  for(reg int i=(b);i<=(n);i++)
#define ll long long
#define inf 2147364847
#define iter iterator

//#include <iostream>
//#include<cstdio>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include <stack>
//#include <bits/stdc++.h>
//press ctrl+'/' to cancel

#include AWSL
awei_sine;

ll s[200005];

int main()
{
    ll t, n, k;
    cin >> t;
    while (t--) {
        ll N, mid, cnt = 0, ans = 0;
        scanf ("%lld %lld", &n, &k);
        N = n * k;
        mid = (n % 2) ? n / 2 + 1 : n / 2;
        for (int i = 0; i < N; i++)
            scanf ("%lld", &s[i]);
        for (int i = k * (mid - 1); i < N; i += (n - mid + 1))
            ans += s[i];
        printf("%lld\n", ans);
    }
    return 0;
}