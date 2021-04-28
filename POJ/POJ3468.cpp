#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll a[100010],b[100010],N;

ll lowbit(ll x){	return x&(-x);}

void update(ll i,ll val)
{
	ll x=i;
	while(i<=N){
		a[i]+=val;
		b[i]+=(val*(x-1));
		i+=lowbit(i);
	}
}

ll getsum(ll i)
{
	ll res=0,x=i;
	while(i>0){
		res+=(a[i]*x-b[i]);
		i-=lowbit(i);
	}
	return res;
}

int main()
{
	ll Q,num1,num2=0;
	scanf ("%lld %lld",&N,&Q);
	for (int i=1;i<=N;i++){
		scanf ("%lld",&num1);
		update(i,num1-num2);
		num2=num1;
	}
	for (int i=1;i<=Q;i++)
	{
		char op=getchar();
		ll x,y,k;
		if (op=='C') {
			scanf ("%lld %lld %lld",&x,&y,&k);
			update(x,k);
			update(y+1,-k);
		}
		else if (op=='Q') {
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",getsum(y)-getsum(x-1));
		}
		else i--;
	}
	return 0;
}
