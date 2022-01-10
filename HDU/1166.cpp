#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[50010],n;

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
	int num,x,y,T;
	char op[10];
	scanf ("%d ",&T);
	for (int i=1;i<=T;i++){
		printf("Case %d:\n",i);
		scanf("%d ",&n);
		memset(a,0,sizeof(int)*(n+1));
		for (int i=1;i<=n;i++){
			scanf ("%d ",&num);
			update(i,num);
		}
		while(1)
		{
			memset(op,0,sizeof(op));
			scanf ("%s",&op);
			if (!strcmp("End",op)) break;
			else if (strcmp("Add",op)==0) {
				scanf("%d %d ",&x,&y);
				update(x,y);
			}
			else if (!strcmp("Sub",op)) {
				scanf("%d %d ",&x,&y);
				update(x,-y);
			}
			else if (!strcmp("Query",op)){
				scanf("%d %d ",&x,&y);
				printf("%d\n",getsum(y)-getsum(x-1));
			}
		}
	}
	return 0;
}
