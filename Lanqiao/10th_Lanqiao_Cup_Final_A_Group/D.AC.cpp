#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll N=1e5,inf=1e18;
bool vis[N+10];
ll prime[N+10],tot=0,mi;
void get_prime() // 素数筛
{
	memset(vis,1,sizeof(vis));
	vis[0]=vis[1]=0;
	for(int i=2;i<=N;i++)
	{
		if(vis[i])prime[tot++]=i;
		for(int j=0;j<tot&&i*prime[j]<=N;j++)
		{
			vis[i*prime[j]]=0;
			if(i%prime[j]==0)break;
		}
	}
}
ll qpow(ll a,ll b) // 快速幂
{
	ll s=1;
	while(b)
	{
		if(b&1)s=s*a;
		b/=2;
		a*=a;
	}
	return s;
}
ll dfs(ll x,vector<ll>g) // 将x分解成若干个数的乘积 
{
	if(vis[x]||x==1)return qpow(2,x-1); // 特判质数和1
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ll t=x/i; // 大的那个数 
			g.push_back(i);
			
			// 更新mi 
			vector<ll>tmp=g;
			tmp.push_back(t); 
			sort(tmp.begin(),tmp.end(),greater<ll>());
			ll s=1;
			for(int j=0;j<tmp.size();j++)
				s*=qpow(prime[j],tmp[j]-1);	
			mi=min(mi,s);
			
			dfs(t,g);
			g.pop_back();
		}
	}
	return mi;
}
int main() 
{
    freopen("./out.txt" , "w", stdout);
	get_prime();
	ll ans=0;
	vector<ll>g;
	for(int i=1;i<=60;i++)
	{
		mi=inf;
		g.clear();
		ll ts=dfs(i,g);
		ans+=ts;
		cout << i << " " << ts << '\n';
	}
	cout << "ans :" << ans << '\n';
	return 0;
}
