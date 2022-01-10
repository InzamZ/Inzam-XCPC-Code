#include <bits/stdc++.h>
using namespace std;

double a[100010], b[100010], sum = 0;

int main()
{
    int t, n, ac = 0, bc = 0;
    scanf("%d", &t);
    while (t--) {
        sum = 0;
        ac = 0, bc = 0;
        scanf("%d", &n);
        for (int x = 0; x < n * 2; x++) {
            double y, z;
            scanf("%lf%lf", &y, &z);
            if (y == 0)
                a[ac++] = fabs(z);
            else
                b[bc++] = fabs(y);
        }
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; i++)
            sum += sqrt((a[i] * a[i]) + (b[i] * b[i]));
        printf("%.12lf\n", sum);
    }
    return 0;
}