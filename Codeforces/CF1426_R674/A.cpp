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
    int t, n, x;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d %d", &n, &x);
        if (n <= 2)
            printf("1\n");
        else if ((n - 2) % x == 0)
            printf("%d\n", (n - 2) / x + 1);
        else
            printf("%d\n", (n - 2) / x + 2);
    }
    return 0;
}