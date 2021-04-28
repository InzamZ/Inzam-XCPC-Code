#include <bits/stdc++.h>
using namespace std;

int fa[1000010];
bool ap[1000010];

int ifind(int x)
{
    return fa[x] == x ? x : (fa[x] = ifind(fa[x]));
}

void imerge(int x, int y)
{
    fa[ifind(x)] = ifind(y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (ifind(a) != i) imerge(a, i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ap[ifind(i)] == false){
            ans++, ap[fa[i]] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}