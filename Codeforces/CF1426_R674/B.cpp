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

bool typ;

int main()
{
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n, m;
        typ = false;
        scanf ("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if (a == d && b == c)
                typ = true;
            else if (b == c)
                typ = true;
        }
        if (m % 2 != 0)
            typ = false;
        printf("%s\n", typ ? "YES" : "NO");
    }
    return 0;
}