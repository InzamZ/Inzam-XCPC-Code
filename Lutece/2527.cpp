#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
const int maxn = 1e5 + 10;
int st[maxn][30];
int a[maxn], bin[35], lg[maxn];

void getst(int n)
{
    bin[0] = 1;
    lg[0] = -1;
    for (int i = 1; i <= 18; i++)
        bin[i] = 2 * bin[i - 1];
    for (int i = 1; i <= 1e5 + 10; i++)
        lg[i] = lg[i / 2] + 1;
    for (int j = 0; j <= 18; j++)
        for (int i = 0; i + bin[j] - 1 <= n; i++) {
            if (j == 0)
                st[i][j] = a[i];
            else {
                st[i][j] = max(st[i][j - 1], st[i + bin[j - 1]][j - 1]);
#ifdef debug
                printf("%d %d: %d %d final %d\n", i, j, st[i][j - 1], st[i + bin[j - 1]][j - 1], st[i][j]);
#endif
            }
        }
}

int stsearch(int l, int r)
{
    if (l == r)
        return a[l];
    int t = lg[r - l + 1];
    return max(st[l][t], st[r - bin[t] + 1][t]);
}

int main()
{
    int n, ans = 0, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    getst(n);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", stsearch(l, r));
    }
    return 0;
}