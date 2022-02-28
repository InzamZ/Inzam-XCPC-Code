//InzamZ

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
int num[200010];
int p[200010];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 1e7, top = 1;
        scanf("%d", &n);
        memset(p, 0, sizeof(int) * (n + 1));
//      memset(s,0,sizeof(int)*(n+1));
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &num[ top++ ]);
            if (i >= 2 && num[top - 1] == num[top - 2])
                top--;
            else
                p[num[top - 1]]++;
        }
        --top;
        if (top == 1)
            cout << 0 << endl;
        else if (num[1] == num[top] && p[num[1]] == 2)
            cout << 1 << endl;
        else {
            for (int i = 1; i <= n; i++) {
                bool flag = false;
                if (p[i])
                    flag = true;
                if (i == num[1])
                    p[i]--;
                if (i == num[top])
                    p[i]--;
                if ( flag && p[i] < ans)
                    ans = p[i] + 1;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}