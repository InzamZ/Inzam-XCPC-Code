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
	int m,k,num1=0,num2=0,op,x,y;
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf ("%d",&num1);
		update(i,num1-num2);
		num2=num1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf ("%d",&op);
		if (op==1) {
			scanf("%d %d %d",&x,&y,&k);
			update(x,k);
			update(y+1,-k);
		}
		else if (op==2) {
			scanf("%d",&x);
			printf("%d\n",getsum(x));
		}
	}
	return 0;
}
