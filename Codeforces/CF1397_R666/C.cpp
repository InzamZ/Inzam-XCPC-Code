#include <iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include <stack>
using namespace std;

const int maxn = 1e5 + 10;
#define F(i,b,n)  for(int i=(b);i<(n);i++)
#define f(i,b,n)  for(int i=(b);i<=(n);i++)
#define ll long long

ll a[maxn];

int main()
{
    int n;
    scanf ("%d", &n);
    f(i, 1, n) scanf ("%lld", &a[i]);
    if (n == 1) {
        f(i, 1, 3) {
            printf("1 1\n%lld\n", -a[i]);
            a[i] = 0;
        }
    }
    else {
        cout << "1 " << n << '\n';
        f(i, 1, n) {
            cout << -a[i]*n;
            if (i != n)
                putchar(' ');
        }
        putchar('\n');
        cout << "1 " << n - 1 << '\n';
        f(i, 1, n - 1) {
            cout << a[i]*(n - 1);
            if (i != n - 1)
                putchar(' ');
        }
        putchar ('\n');
        cout << n << ' ' << n << '\n';
        cout << a[n]*(n - 1);
        putchar('\n');
    }
    return 0;
}