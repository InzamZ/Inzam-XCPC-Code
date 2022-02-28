#include <bits/stdc++.h>
using namespace std;
#define maxn (1e5+10)
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f

int main()
{
    ios::sync_with_stdio(false);
    int T,n,mx,cnt=0,x;
    cin>>T;
    while (T--)
    {
        cnt=0;
        cin>>n;
        for (int i=1;i<=n;++i)
        {
            cin>>x;
            if (i==1) mx=x,cnt=1;
            else 
            {
                if (x<mx) mx=x,cnt=1;
                else if (x==mx) ++cnt;
            }
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}