//InzamZ
//
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int T = 1, p, t, ans = 0;
    // T=_read();
    while (T--) {
        ans = 0;
        scanf("%d %d", &p, &t);
        ans = (t / 12) + (t % 12 != 0);
        ans *= p;
        printf("%d\n", ans);
    }
    return 0;
}