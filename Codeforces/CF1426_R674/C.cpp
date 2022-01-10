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
#define f(i,b,n)  for(register int i=(b);i<=(n);i++)
#define ll long long

const char *turns = "FLR";
const char *dires = "ESWN";

int dx[] = {1, 0, -1, 0}; //传统的坐标系变换
int dy[] = {0, -1, 0, 1};

int dr[] = {1, 0, -1, 0}; //行列变化
int dc[] = {0, -1, 0, 1};



int main()
{
    int t, n, ans = 1e9, x;
    bool flag = true;
    scanf ("%d", &t);
    while (t--) {
        flag = true;
        ans = 1e9;
        scanf ("%d", &n);
        if (n == 1) {
            printf("0\n");
            continue;
        }
        for (int y = 1; flag; y++) {
            if (n % (y + 1) == 0)
                x = n / (y + 1) - 1;
            else
                x = n / (y + 1);
            flag = false;
            if (ans >= x + y) {
                flag = true;
                ans = x + y;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}