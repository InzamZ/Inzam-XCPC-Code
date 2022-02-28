#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[200005];
int suf[200005],sufo[200005],fa[200005];
int main()
{
	int N,nf=0;
	scanf ("%d",&N);
	scanf ("%s",s);
	for (int i=1;i<N;i++) fa[i]=i-1;
	for (int i=0;i<N;i++)
	{
		if (s[i]=='f') suf[i]=s[fa[i]]+1;
		else if (suf[fa[i]] && s[i]=='o' ) suf[i]=0,sufo[i]++;
		else if (sufo[fa[i]] && s[i]=='x') 
		{
			fa[i+1]=fa[i-1],nf++;
			suf[i-1]--;
		}
		else suf[i]=0,sufo[i]=0;
	}
	cout<<N-3*nf<<endl;
	return 0;
}