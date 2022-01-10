#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
using ll = long long;

char s[maxn][maxn];

int main()
{
    int n, m, x, y, ans = 1;
    scanf("%d %d %d %d", &n, &m, &y, &x);
    --x;
    --y;
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    for (int i = x + 1; i < m && s[y][i] != '#'; ++i)
        ans++;
    for (int i = x - 1; i >= 0 && s[y][i] != '#'; --i)
        ans++;
    for (int i = y + 1; i < n && s[i][x] != '#'; ++i)
        ans++;
    for (int i = y - 1; i >= 0 && s[i][x] != '#'; --i)
        ans++;
    printf("%d", ans);
    return 0;
}