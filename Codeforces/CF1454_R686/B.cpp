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
int s[200010];
int p[200010];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, ans = -1;
        scanf("%d", &n);
        memset(p, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= n; i++) {
            int num;
            scanf ("%d", &num);
            s[num] = i;
            p[num]++;
        }
        for (int i = 1; i <= n; i++) {
            if (p[i] == 1) {
                ans = i;
                break;
            }
        }
        if (ans == -1)
            printf("-1\n");
        else
            printf("%d\n", s[ans]);
    }
    return 0;
}