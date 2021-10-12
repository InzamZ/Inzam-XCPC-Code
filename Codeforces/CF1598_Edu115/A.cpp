//Author: InzamZ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e4 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = true;
int T = 1, n, ans = 0;
char a1[maxn], a2[maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        flag = true;
        scanf("%d", &n);
        scanf("%s", a1);
        scanf("%s", a2);
        IF(i, 0, n - 1) {
            if (a1[i] == '1' && a2[i] == '1') {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}