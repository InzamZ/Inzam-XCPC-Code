#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

int T = 1, h, w, cur = 0, a;
ll ans = 1e18, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        cur = 0;
        scanf("%d %d", &h, &w);
        if (h % 2 == 1) {
            for (int i = 1; i <= h; i ++) {
                if (i % 2 == 0)
                    for (int j = 1; j <= w; j++)
                        printf("%c", '0');
                else if (i != 1 && i != h)
                    for (int j = 1; j <= w; j++)
                        printf("%c", ((j == 1 || j == w ) && i % 2 == 1) ? '1' : '0');
                else
                    for (int j = 1; j <= w; j++)
                        printf("%c", ( j % 2 == 1) ? '1' : '0');
                putchar('\n');
            }
        }
        else {
            for (int i = 1; i <= h - 2; i ++) {
                if (i % 2 == 0)
                    for (int j = 1; j <= w; j++)
                        printf("%c", '0');
                else if (i != 1 && i != h)
                    for (int j = 1; j <= w; j++)
                        printf("%c", ((j == 1 || j == w ) && i % 2 == 1) ? '1' : '0');
                else
                    for (int j = 1; j <= w; j++)
                        printf("%c", ( j % 2 == 1) ? '1' : '0');
                putchar('\n');
            }
            for (int j = 1; j <= w; j++)
                printf("%c", '0');
            putchar('\n');
            for (int j = 1; j <= w; j++)
                printf("%c", ( j % 2 == 1) ? '1' : '0');
            putchar('\n');
        }
    }
    return 0;
}