#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

ll T = 1, n, a, b, cost = 0, c;
char s[100025];
int main()
{
    while (T--) {
        bool flag = true;
        scanf("%lld", &n);
        scanf("%s", s);
        int i = 0;
        for (i = 0; i < n; ++i) {
            if (s[i] == '1')
                break;
        }
        i++;
        if (i % 2 == 1)
            printf("Takahashi\n");
        else
            printf("Aoki\n");
        }
    return 0;
}