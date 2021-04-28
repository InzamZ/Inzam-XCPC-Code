#include <iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

#define F(i,b,n)  for(int i=(b);i<(n);i++)
#define f(i,b,n)  for(int i=(b);i<=(n);i++)
#define ll long long

const char *turns = "FLR";
const char *dires = "ESWN";
const int maxn = 110;

int dx[] = {1, 0, -1, 0}; //传统的坐标系变换
int dy[] = {0, -1, 0, 1};

int dr[] = {1, 0, -1, 0}; //行列变化
int dc[] = {0, -1, 0, 1};
int mex1 = 0, mex2 = 0;
int s[maxn];

int main()
{
    int T;
    scanf ("%d", &T);
    while (T--) {
        memset(s, 0, sizeof(s));
        int ans = 0, flag = 0;
        int n;
        scanf ("%d", &n);
        F(i, 0, n) {
            int num;
            scanf ("%d", &num);
            s[num]++;
        }
        for (int i = 0; flag != 2; i++) {
            if (s[i] == 0) {
                if (flag == 0)
                    flag = 2, ans = ans + i * 2;
                else if (flag == 1)
                    flag = 2, ans += i;
            }
            else if (s[i] == 1 && flag == 0)
                flag++, ans += i;
        }
        printf("%d\n", ans);
    }
    return 0;
}