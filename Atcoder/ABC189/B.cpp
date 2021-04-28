#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
const int maxn = 1e6;

int main()
{
    int n, x, v, p;
    scanf ("%d %d", &n, &x);
    x *= 100;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &v, &p);
        x -= v * p;
        if (x < 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}