//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, m1, m2, ans = 0;
double n1, n2;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%lf %d", &n1, &m1);
        while (n1 >= 10) {
            n1 /= 10;
            ++m1;
        }
        scanf("%lf %d", &n2, &m2);
        while (n2 >= 10) {
            n2 /= 10;
            ++m2;
        }
        if (m2 == m1 && n1 == n2) printf("=\n");
        else if (m1 > m2 || (m1 == m2 && n1 > n2)) printf(">\n");
        else printf("<\n");
    }
    return 0;
}