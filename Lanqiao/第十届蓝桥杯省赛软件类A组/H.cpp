#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int a[100010], n;
set<int>s;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 1100010; ++i)
        s.insert(i);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (s.find(a[i]) != s.end())
            s.erase(a[i]);
        else {
            a[i] = *s.lower_bound(a[i]);
            s.erase(a[i]);
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", a[i], i != n ? ' ' : '\n');
    return 0;
}