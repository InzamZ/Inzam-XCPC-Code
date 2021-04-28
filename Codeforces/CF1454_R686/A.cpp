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

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 2; i <= n; i++)
            cout << i << ' ';
        cout << 1 << endl;
    }
    return 0;
}