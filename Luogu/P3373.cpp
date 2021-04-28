#include <cstdio>
#include<iostream>
using namespace std;

#define M ((l+r)/2)
#define lo (o*2)
#define ro (o*2+1)
#define len(a,b) ((b)-(a)+1)

typedef long long ll;
ll m,n,p,x,y,k,op;
ll sum[400010],lazy1[400010],lazy2[400010],num[100010];

void build(int o,int l,int r)
{
	lazy1[o]=1;
	if (l==r) {	sum[o]=num[l]%p;	return ;}
	build(lo,l,M);
	build(ro,M+1,r);
	sum[o]=(sum[lo]+sum[ro])%p;
}

void pushdown(int o,int l,int r)
{
	lazy1[lo]*=lazy1[o];	lazy1[lo]%=p;
	lazy1[ro]*=lazy1[o];	lazy1[ro]%=p;
	lazy2[lo]=lazy2[lo]*lazy1[o]+lazy2[o];	lazy2[lo]%=p;
	lazy2[ro]=lazy2[ro]*lazy1[o]+lazy2[o];	lazy2[ro]%=p;
	sum[lo]=((sum[lo]*lazy1[o])+lazy2[o]*len(l,M))%p;
	sum[ro]=((sum[ro]*lazy1[o])+lazy2[o]*len(M+1,r))%p;
	lazy1[o]=1;
	lazy2[o]=0;
}

ll getsum(int o,int l,int r)
{
	ll res=0;
	if (x<=l && r<=y) return sum[o]%p;
	pushdown(o,l,r);
	if ( M >= x) 
	{
		res+=getsum(lo,l,M);
		res%=p;
	}
	if ( M < y) 
	{
		res+=getsum(ro,M+1,r);
		res%=p;
	}
	return res%p;
}

void addval(int o,int l,int r)
{
	if (x<=l && r<=y) 
	{
		sum[o]=(sum[o]+k*len(l,r))%p;
		lazy2[o]+=k;	lazy2[o]%=p;
		return ;
	}
	pushdown(o,l,r);
	if ( M >= x ) addval(lo,l,M);
	if ( M < y ) addval(ro,M+1,r);
	sum[o]=sum[lo]+sum[ro];
	sum[o]%=p;
}

void multival(int o,int l,int r)
{
	if (x<=l && r<=y) 
	{
		sum[o]=(sum[o]*k)%p;
		lazy1[o]*=k;lazy1[o]%=p;
		lazy2[o]*=k;lazy2[o]%=p;
		return ;
	}
	pushdown(o,l,r);
	if ( M >= x) multival(lo,l,M);
	if ( M < y) multival(ro,M+1,r);
	sum[o]=sum[lo]+sum[ro];
	sum[o]%=p;
}

int main()
{
	scanf ("%lld%lld%lld",&n,&m,&p);
	for(int i=1;i<=n;i++) scanf ("%lld",&num[i]);
	build(1,1,n);
	while (m--)
	{
		scanf ("%lld%lld%lld",&op,&x,&y);
		if (x>y) swap(x,y);
		if (op==1 || op==2) 
		{
			scanf ("%lld",&k);
			if (op==1) multival(1,1,n);
			else addval(1,1,n);
		}
		if (op==3) printf("%lld\n",getsum(1,1,n));
	}
	return 0;
}
