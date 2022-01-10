#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;
ll sum[400000],add[400000],num[100010],k,ans;
ll n,m,qr,ql;

#define lo 2*o
#define ro 2*o+1
#define len(a,b) ((b)-(a)+1)

void build(ll o,ll L,ll R)
{
	add[o]=0;
	if (L==R) 
	{
		sum[o]=num[L];
		return ;
	}
	ll M=(L+R)/2;
	build(lo,L,M);
	build(ro,M+1,R);
	sum[o]=sum[lo]+sum[ro];
}

void pushdown(ll o,ll L,ll R)
{
	ll M=(L+R)/2;
    add[lo]+=add[o];
    add[ro]+=add[o];
    sum[lo]+=len(L,M)*add[o];
    sum[ro]+=len(M+1,R)*add[o];
    add[o]=0;
}

ll getsum(ll o,ll L,ll R)
{
	ll res=0;
	if (ql<=L && R<=qr) {
		return sum[o];
	}
	pushdown(o,L,R);
	ll M=(L+R)/2;
	if ( M >= ql) res+=getsum(lo,L,M);
	if ( M < qr ) res+=getsum(ro,M+1,R);
	return res;
}

void addval(ll o,ll L,ll R)
{
	if (ql<=L && R<=qr) {
		sum[o]+=k*len(L,R);
		add[o]+=k;
		return ;
	}
	pushdown(o,L,R);
	ll M=(L+R)/2;
	if( M >= ql ) addval(lo,L,M);
	if ( qr > M ) addval(ro,M+1,R);
	sum[o]=sum[lo]+sum[ro];
}

int main()
{
	scanf ("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf ("%lld",&num[i]);
	}
	build(1,1,n);
	for (int i=1;i<=m;i++){
		ll op;
		scanf ("%lld %lld %lld",&op,&ql,&qr);
		if (ql>qr) swap(ql,qr);
		if (op==2)
		{
			ans=getsum(1,1,n);
			printf("%lld\n",ans);
		}
		if (op==1) 
		{
			scanf ("%lld",&k);
			addval(1,1,n);
		}
	}
	return 0;
}
