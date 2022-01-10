#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

char s[maxn];

int main()
{
    int T = 1, n;
    scanf("%s", s);
    int l = 1, r = 1e9, mid = (l + r) / 2;
    // printf("%d\n", strcmp("end", "end"));
    // printf("%d\n", strcmp(s, "end"));
    while (strcmp(s, "start") == 0) {
        int x = 0, y = 1;
        do {
            printf("? %d %d\n", x, y);
            fflush(stdout);
            scanf("%s", s);
            if (s[0] == 'y') {
                x = y;
                y *= 2;
            }
        }
        while (s[0] == 'y');
        // printf("%d\n", x);
        if (x == 0)
            l = r = 1;
        else
            l = x - 1, r = y;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            printf("? %d %d\n", l, mid);
            fflush(stdout);
            scanf("%s", s);
            if (s[0] == 'x')
                r = mid ;
            else if (s[0] == 'y')
                l = mid ;
            else
                l = 1e9;
        }
        printf("! %d\n", r);
        fflush(stdout);
        scanf("%s", s);
    }
    return 0;
}