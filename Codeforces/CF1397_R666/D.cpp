#include <bits/stdc++.h>
using namespace std;

#define F(i,b,n)  for(int i=(b);i<(n);i++)
#define f(i,b,n)  for(int i=(b);i<=(n);i++)
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    int T, n, sum, maxn;
    cin >> T;
    while (T--) {
        sum = 0;
        maxn = -1;
        cin >> n;
        vector<int>a;
        f(i, 1, n) {
            int sto;
            cin >> sto;
            a.push_back(sto);
            maxn = max(maxn, sto);
            sum += sto;
        }
        if (maxn > sum / 2)
            cout << 'T' << endl;
        else if (sum % 2 == 0)
            cout << "HL" << endl;
        else
            cout << 'T' << endl;
    }
    return 0;
}