//DYf3244 (Teammate)
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n;
int a[maxn];
int ans[maxn];

int main ()
{
	IOS;
	int T ; cin >> T;
	for ( int cas = 1 ; cas <= T ; cas++ )
	{
		cin >> n;
		if ( n % 7 == 0 ) 
		{
			ans[cas] = n ;
			continue;
		}
		
		int res = n % 7;
		int last = n % 10;
		if ( last - res >= 0 ) 
			ans[cas] = n - res;
		else ans[cas] = n + 7 - res;
	}
	for ( int i = 1 ; i <= T ; i++ )
		cout << ans[i] << endl;
}