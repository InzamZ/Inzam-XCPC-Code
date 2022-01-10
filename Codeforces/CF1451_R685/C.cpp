#include <bits/stdc++.h>
using namespace std;

int a[30], b[30];

int main()
{
    int t, n, k;
    char ch;
    bool flag;
    scanf ("%d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        flag = true;
        scanf ("%d %d ", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%c", &ch);
            ++a[ch - 'a'];
        }
        getchar();
        for (int i = 1; i <= n; i++) {
            scanf("%c", &ch);
            ++b[ch - 'a'];
        }
        for (int i = 0; i < 25 && flag; i++) {
            if (a[i] == b[i])
                continue;
            else if (a[i] < b[i])
                flag = false;
            else if ((a[i] - b[i]) % k == 0)
                a[i + 1] += (a[i] - b[i]);
            else
                flag = false;
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
