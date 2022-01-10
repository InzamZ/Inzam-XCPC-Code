#include <bits/stdc++.h>
using namespace std;

int A[110];
bool t[10010];

int main()
{
    int N, count = 0, mx = 0, mn = 0;
    for (int i = 2; i <= 10000; i++) {
        if (t[i])
            continue;
        for (int j = i * 2; j <= 10000; j += i)
            t[j] = 1;
    }
    scanf ("%d", &N);
    for (int i = 0; i < N; i++)
        scanf ("%d", &A[i]);
    for (int i = 2; i <= 10000; i++) {
        if (t[i])
            continue;
        count = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] % i == 0)
                count++;
        }
        if (count > mx)
            mx = count, mn = i;
    }
    printf("%d\n", mn);
    return 0;
}
