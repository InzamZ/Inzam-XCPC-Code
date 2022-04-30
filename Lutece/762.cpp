#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n, k;
int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> k;
        if ( k < 2 || n == 1 ) {
            if ( n == 2 && k == 1 ) {
                ans[cas] = 1;
            }
            else {
                ans[cas] = 0;
            }
            continue;
        }

        if ( k > n-1) 
            k = n-1;
        ans[cas] = n * k / 2;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}