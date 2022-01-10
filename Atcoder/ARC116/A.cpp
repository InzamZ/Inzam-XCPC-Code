#include <bits/stdc++.h>
using namespace std;
#define maxn (1e5+10)
int main()
{
    ios::sync_with_stdio(false);
    long long T, n;
    cin >> T;
    while (T--) {
        long long ecnt = 0;
        cin >> n;
        while (n % 2 == 0) {
            ++ecnt;
            n /= 2;
        }
        if (ecnt == 1)
            cout << "Same" << endl;
        else if (ecnt == 0)
            cout << "Odd" << endl;
        else
            cout << "Even" << endl;
    }
    return 0;
}