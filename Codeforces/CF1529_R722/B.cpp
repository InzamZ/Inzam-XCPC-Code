#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f

int num[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int T, n, mx, cnt = 0, x;
    cin >> T;
    while (T--) {
        cin >> n;
        cnt = 1;
        for (int i = 1; i <= n; ++i)
            cin >> num[i];
        sort(num + 1, num + 1 + n);
        for (int i = 2; i <= n; i++) {
            if (i == 2)
                mx = abs(num[2] - num[1]);
            else
                mx = min(mx, abs(num[i] - num[i - 1]));
            if (mx >= num[i])
                ++cnt;
            else
                break;
        }
        cout << cnt << '\n';
    }
    return 0;
}