//InzamZ

#include <bits/stdc++.h>
using namespace std;

char c[110];

int main()
{
    int t, q, n, l, r;
    bool flag;
    scanf ("%d", &t);
    while (t--) {
        flag = false;
        scanf ("%d %d ", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%c", &c[i]);
        for (int i = 1; i <= q; i++) {
            flag = false;
            scanf("%d %d", &l, &r);
            for (int i = 1; i < l; i++) {
                if (c[i] == c[l]) {
                    flag = true;
                    break;
                }
            }
            for (int i = r + 1; i <= n && !flag; i++) {
                if (c[i] == c[r]) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}