#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f
long long t[maxn], cnt[maxn*2];

int main()
{
    int T, n;
    cin >> T;
    while (T--) {
        long long ans=0;
        long long l=400000,r=0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &t[i]);
            t[i] -= i;
        }
        for (int i = 1; i <= n; ++i) {
            ++cnt[t[i]+200000];
            l=min(l,t[i]+200000);
            r=max(t[i]+200000,r);
        }
        for (int i=l;i<=r;++i)
        {
            if (cnt[i]>=2) ans+=(cnt[i]*(cnt[i]-1)/2);
        }
        cout<<ans<<endl;
        for (int i=l;i<=r;++i) cnt[i]=0;
    }
    return 0;
}