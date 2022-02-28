//InzamZ

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

int main()
{
    int t, c0, c1, h, n, ans;
    char ch;
    cin >> t;
    while (t--) {
        ans = 0;
        scanf ("%d %d %d %d ", &n, &c0, &c1, &h);
        if (c0 >= c1 + h)
            c0 = c1 + h;
        else if (c1 >= c0 + h)
            c1 = c0 + h;
        for (int i = 0; i < n; i++) {
            ch = getchar();
            if (ch == '0')
                ans += c0;
            else
                ans += c1;
        }
        cout << ans << endl;
    }
    return 0;
}