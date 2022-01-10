#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f
int pos[maxn], cnt = 0;
char s[maxn];

int main()
{
    int T, n, aims;
    long long ans = 0;
    cin >> T;
    while (T--) {
        cnt = 0;
        ans = 0;
        memset(s,0,sizeof(char)*(n));
        scanf("%d %s",&n, s);
        for (int i = 0; i < n; ++i)
            if (s[i] == '*')
                pos[cnt++] = i;
        aims = pos[cnt / 2];
        //cout<<aims<<endl<<cnt<<endl;
        for (int i=0;i<cnt;++i)
        {
            //cout<<i<<' '<<pos[i]<<endl;
            ans=ans+abs(pos[i]-aims)-abs(i-cnt/2);
        }
        cout<<ans<<endl;
        //for (int i=0;i<cnt;++i) pos[i]=0;
    }
    return 0;
}