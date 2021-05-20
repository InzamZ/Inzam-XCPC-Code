#include <iostream>
using namespace std;

using ull = unsigned long long;

ull s[maxn],p[maxn];

int tot=0;
ull d[70];
bool xorit[maxn];
vector<int>

int main()
{
    ull n,op,k;
    scanf("%ull",&n);
    for (int i=1;i<=n;++i)
    {
        if (op==0)
        {
            ull temp=1,cnt=k;
            temp<<=63;
            p[0]=0;
            for (int i=64;i>0;--i)
            {
                if (temp & k)
                {
                    if (d[i]) 
                    {
                        k^=d[i];
                        p[0]=p[0]|temp;
                    }
                    else 
                    {
                        d[i]=k;
                        p[i]=p[0];
                        break;
                    }
                }
                temp>>=1;
            }
        }
        else 
        {
            ull temp=1,cnt=k;
            temp<<=63;
            p[0]=0;
            for (int i=64;i>0;--i)
            {
                if (temp & k)
                {
                    if (d[i]==k) 
                    {
                        k^=d[i];
                        p[0]=p[0]|temp;
                    }
                }
                temp>>=1;
            }
        }
        ull ans=0;
        for (int i=64;i>0;--i)
        {
            if ((ans^d[i])>ans) ans^=d[i];
        }
        printf("%ull\n",ans);
    }
}