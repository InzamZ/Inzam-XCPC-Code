//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn =  110;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef FREAD
static char buf[1000000], *p1 = buf, *p2 = buf, obuf[1000000], *p3 = obuf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
template<typename item>
inline void read(register item &x)
{
    x = 0; register int f = 1; register char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    x *= f;
}
#endif

char s1[maxn], s2[maxn];

int main()
{
    int T = 1, n;
    scanf("%d", &T);
    while (T--) {
        vector<int>ans;
        scanf("%s %s", s1, s2);
        int len1 = strlen(s1), len2 = strlen(s2), flag = 0;
        int i = len1 - 1, j = len2 - 1;
        for (i, j; i >= 0; --i) {
            if (s1[i] <= s2[j]) {
                ans.push_back(s2[j] - s1[i]);
                --j;
            }
            else if (s1[i] > s2[j] && (j == 0 || s2[j - 1] != '1')) {
                flag = 1;
                break;
            }
            else {
                ans.push_back(s2[j] - s1[i] + 10);
                j -= 2;
            }
        }
        while (j >= 0)
            ans.push_back(s2[j--] - '0');
        if (flag)
            printf("-1\n");
        else {
            int k;
            for (k = ans.size() - 1; ans[k] == 0 && k > 0; --k)
                ;
            for (k; k >= 0; k--)
                printf("%d", ans[k]);
            putchar('\n');
        }
        for (int i = len1 - 1; i >= 0 ; --i)
            s1[i] = 0;
        for (int i = len2 - 1; i >= 0 ; --i)
            s2[i] = 0;
    }
    return 0;
}