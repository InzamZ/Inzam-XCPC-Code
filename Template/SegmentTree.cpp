#include<cstdio>
#include<iostream>
using namespace std;

#define maxn 100010
typedef long long ll;
ll num[100010],k,ans;
ll n,m,qr,ql,tot=0,rt=0;
#define lo (tree[o].son[0])
#define ro (tree[o].son[1])
#define len(a,b) ((b)-(a)+1)

struct node
{
    ll val,lazy;
    ll son[2];
}tree[maxn*4];

void build(ll o,ll L,ll R)
{
	tree[o].lazy=0;
	if (L==R) {	tree[o].val=num[L];	return ;}
	ll M=(L+R)/2;
    tree[o].son[0]=++tot;
	build(lo,L,M);
    tree[o].son[1]=++tot;
	build(ro,M+1,R);
	tree[o].val=tree[lo].val+tree[ro].val;
}

void pushdown(ll o,ll L,ll R)
{
	ll M=(L+R)/2;
    tree[lo].lazy+=tree[o].lazy;
    tree[ro].lazy+=tree[o].lazy;
    tree[lo].val+=len(L,M)*tree[o].lazy;
    tree[ro].val+=len(M+1,R)*tree[o].lazy;
    tree[o].lazy=0;
}

ll getsum(ll o,ll L,ll R)
{
	ll res=0;
	if (ql<=L && R<=qr) {
		return tree[o].val;
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
		tree[o].val+=k*len(L,R);
		tree[o].lazy+=k;
		return ;
	}
	pushdown(o,L,R);
	ll M=(L+R)/2;
	if( M >= ql ) addval(lo,L,M);
	if ( qr > M ) addval(ro,M+1,R);
	tree[o].val=tree[lo].val+tree[ro].val;
}

int main()
{
	scanf ("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf ("%lld",&num[i]);
	}
	build(rt,1,n);
	for (int i=1;i<=m;i++){
		ll op;
		scanf ("%lld %lld %lld",&op,&ql,&qr);
		if (ql>qr) swap(ql,qr);
        
		if (op==2){
			ans=getsum(rt,1,n);
			printf("%lld\n",ans);
		}
        
		if (op==1) {
			scanf ("%lld",&k);
			addval(rt,1,n);
		}
	}
	return 0;
}