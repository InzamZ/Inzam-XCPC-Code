#include <bits/stdc++.h>
using namespace std;
int a[500010],n;

int lowbit(int x)
{
	return x&(-x);
}

void update(int i,int val)
{
	while(i<=n)
	{
		a[i]+=val;
		i+=lowbit(i);
	}
}

int getsum(int i)
{
	int res=0;
	while(i>0)
	{
		res+=a[i];
		i-=lowbit(i);
	}
	return res;
}

int main()
{
	int m,num,op,x,y;
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf ("%d",&num);
		update(i,num);
	}
	for (int i=1;i<=m;i++)
	{
		scanf ("%d%d%d",&op,&x,&y);
		if (op==1) update(x,y);
		else if (op==2) printf("%d\n",getsum(y)-getsum(x-1));
	}
	return 0;
}
