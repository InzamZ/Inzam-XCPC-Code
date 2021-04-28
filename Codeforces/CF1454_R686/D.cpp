#define AWSL <bits/stdc++.h>
#define awei_sine using namespace std
#define reg register
#define Kirito(i,b,n)  for(reg int i=(b);i<(n);i++)
#define Mai(i,b,n)  for(reg int i=(b);i<=(n);i++)
#define ll long long
#define inf 2147364847
#define iter iterator

//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<stack>
//#include<bits/stdc++.h>
//press ctrl+'/' to cancel

#include AWSL
awei_sine;
long long s[100010], p[100010];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n, ansn, snum, num, ans = 0;
        scanf("%lld", &n);
        ansn = num = n;
        memset(s, 0, sizeof(s));
        snum = sqrt(n) + 1;
        for (int i = 2; i <= snum; i++) {
            if (n < i)
                break;
            while (n % i == 0)
                ++s[i], n /= i;
            if (s[i] > ans)
                ans = s[i], ansn = i;
        }
        if ( ans == 1 || ans == 0 )
            cout << 1 << '\n' << num << endl;
        else {
            cout << ans << endl;
            for (int i = 1; i < ans; i++) {
                printf("%lld ", ansn);
                num /= ansn;
            }
            cout << num << endl;
        }
    }
    return 0;
}