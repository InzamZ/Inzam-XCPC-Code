#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
const int maxn = 1e6 + 10;

pair<int, int> a[maxn], b[maxn];
int num[maxn], n, m;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    b[0] = a[0] = {n, n + 1};
    a[n + 1] = b[n + 1] = {n, n + 1};
    for (int i = 1; i <= n; i++) {
        if (num[i] <= a[i - 1].first)
            a[i] = {num[i], a[i - 1].first};
        else if (num[i] <= a[i - 1].second)
            a[i] = {a[i - 1].first, num[i]};
        else
            a[i] = a[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        if (num[i] <= b[i + 1].first)
            b[i] = {num[i], b[i + 1].first};
        else if (num[i] <= b[i + 1].second)
            b[i] = {b[i + 1].first, num[i]};
        else
            b[i] = b[i + 1];
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        vector<int>v;
        scanf("%d %d", &l, &r);
        if (l != 1) {
            v.push_back(a[l - 1].first);
            v.push_back(a[l - 1].second);
        }
        if (r != n) {
            v.push_back(b[r + 1].first);
            v.push_back(b[r + 1].second);
        }
        if (l == 1 && r == n)
            printf("%d\n", n + 1);
        else {
            sort(v.begin(), v.end());
            printf("%d\n", v[1]);
        }
    }
    return 0;
}