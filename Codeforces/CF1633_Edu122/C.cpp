//DYf3244 (Teammate)
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(2e6 + 10)
#define FFF freopen("out", "w", stdout);

int ans[maxn];


int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        LL hc, dc;
        LL hm, dm;
        LL k , w , a;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;

        LL cur1 = hm / dc + ( hm % dc != 0); 
        LL cur2 = hc / dm + ( hc % dm != 0);
        if ( cur1 <= cur2 ) 
        {
            ans[cas] = 1;
        }
        else 
        {
            bool flag = 0 ;
            for ( int i = 0 ; i <= k ; i++ )
            {
                LL dc_cur = w*i + dc;
                LL hc_cur = a*(k-i) + hc;
                cur1 = hm / dc_cur + ( hm % dc_cur != 0 );
                cur2 = hc_cur / dm + ( hc_cur % dm != 0);
                if ( cur1 <= cur2 )
                {
                    flag = 1;
                    break;
                }
            }
            ans[cas] = flag;
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}