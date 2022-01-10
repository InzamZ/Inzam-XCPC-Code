#include <bits/stdc++.h>
using namespace std;

long long A[200010], s[200010];

int main()
{
    long long N, ans = 0, cnt = 0;
    scanf ("%lld", &N);
    for (int i = 1; i <= N; i++) {
        scanf ("%lld", &A[i]);
        A[i] += A[i - 1];
        s[i] = max(s[i - 1], A[i]);
    }
    for (int i = 1; i <= N; i++) {
        ans = max(ans, cnt + s[i]);
        cnt += A[i];
    }
    printf("%lld\n", ans);
    return 0;
}
