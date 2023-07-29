#include<cstdio>
#include<vector>
using namespace std;
int s[5005], x[5005];
int main() {
    // freopen("readH.txt","r",stdin);
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &x[i], &s[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        double q;
        scanf("%lf", &q);
        double ans = -1;
        for (int j = 1; j <= n; ++j)
            if (q >= x[j])
                ans = max(1.0 + 1.0 * (q - x[j]) / s[j], ans);
        if (ans == -1)
            puts("-1");
        else
            printf("%.6lf\n", ans);
    }
    return 0;
}