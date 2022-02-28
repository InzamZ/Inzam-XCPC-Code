//InzamZ

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
char str[100010];

int main()
{
    int t, n, k, cnt, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int x = 0; x < n; x++)
            str[x] = 0;
        scanf("%s", str);
        i = 0;
        cnt = 0;
        j = n - 1;
        while (str[i] == str[j] && i < j) {
            i++;
            j--;
            cnt++;
        }
        if (cnt < k)
            printf("NO\n");
        else if (cnt == k && n == cnt * 2)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}