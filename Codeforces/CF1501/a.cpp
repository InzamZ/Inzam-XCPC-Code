#include <bits/stdc++.h>
using namespace std;

const int maxn= 110;
int a[maxn],b[maxn],t[maxn];

int main()
{
    int T,n,cur=0;
    scanf("%d",&T);
    while (T--)
    {
        cur=1;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        for (int i=0;i<n;i++) scanf("%d",&t[i]);
        int ans=0,ab;
        for (int i=0;i<n;i++)
        {
            cur+=t[i];
            ab=(a[i]+b[i])%2?(a[i]+b[i])/2+1:(a[i]+b[i])/2;
            cur+=max(ab-a[i],b[i]-cur);
        }
        printf("%d\n",cur);
    }
    return 0;
}