//InzamZ
#include <cstdio>
#include <algorithm>
using namespace std;

int a[10];

int main()
{
    int T = 1, ans = 0;
    // T=_read();
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    printf("%s\n", a[0]*a[0] + a[1]*a[1] == a[2]*a[2] ? "YES" : "NO");
    return 0;
}