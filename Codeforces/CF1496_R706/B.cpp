#include <bits/stdc++.h>
using namespace std;

int s[100010];
set<int>m;

int main()
{
    int t, n, k, a, b;
    scanf("%d", &t);
    while (t--) {
        m.clear();
        a = 0, b = 0;
        scanf("%d%d", &n, &k);
        for (int x = 0; x < n; x++) {
            scanf("%d", &s[x]);
            m.insert(s[x]);
            b = max(b, s[x]);
        }
        if (k == 0) {
            printf("%d\n", int(m.size()));
            continue;
        }
        sort(s, s + n);
        for (int i = 0; i <= n; i++) {
            if (s[i] == a - 1)
                continue;
            else if (s[i] == a)
                a++;
            else
                break;
        }
        if (a < b && a + 1 == b)
            printf("%d\n", int(m.size()));
        else if (a < b) {
            int num;
            if ((a + b) % 2 == 0)
                num = (a + b) / 2;
            else
                num = (a + b) / 2 + 1;
            if (m.count(num) == 0)
                printf("%d\n", int(m.size()) + 1);
            else
                printf("%d\n", int(m.size()));
        }
        else if (a > b)
            printf("%d\n", int(m.size()) + k);
    }
    return 0;
}