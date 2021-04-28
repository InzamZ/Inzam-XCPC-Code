#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
const int maxn = 1e5 + 10;
int a[maxn];

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = i; j < n; j++) {
            x = min(x, a[j]);
            ans = max(ans, (j - i + 1) * x);
        }
    }
    printf("%d\n", ans);
    return 0;
}