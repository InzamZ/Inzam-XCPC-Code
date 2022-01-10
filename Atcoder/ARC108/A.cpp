#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll S, P;
    cin >> S >> P;
    for (ll i = 1; i <= S / 2; i++) {
        if (i * (S - i) > P)
            break;
        if (i * (S - i) == P) {
            printf("Yes\n");
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}