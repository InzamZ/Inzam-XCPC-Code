//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define LL long long
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int n, ans = 0;
ll T = 1;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) {
        //1的情况
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b, a % b, x, y);
    ll t = y;
    y = x - (a / b) * y; //2的情况
    x = t;
    return r;
}

void exgcd(LL a,LL b,LL&d,LL& x,LL& y){//d=gcd(a,b)
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

LL quickMul(LL a,LL b,LL mod){
	LL ans=0;//这里初值为0 
	while(b){
		if(b&1)
			ans=(ans+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return ans%mod;
} 
LL qpow(LL a,LL b,LL mod){
	LL ans=1;//注意这里初值是1 
	while(b){
		if(b&1)
			ans=quickMul(ans,a,mod)%mod;
		a=quickMul(a,a,mod)%mod;
		b>>=1;
	}
	return ans%mod;
}

// __int128_t qpow(__int128_t a, __int128_t b,__int128_t p)
// {
//     ll res = 1;
//     while (b) {
//         if (b & 1)
//             res = res * a % p;
//         a = a * a % p;
//         b >>= 1;
//     }
//     return res % p;
// }

int main()
{
    ll ans1, ans2, d = 212353, c = 20190324, n = (891234941ll) * (1123984201ll);
    ll tmp = (891234941ll - 1) * (1123984201ll - 1);
    ans1 = ans2 = 0;
    ll e = exgcd(d, tmp, ans1, ans2);
    ans1 = (ans1 + tmp) % tmp;
    // cout << ans1 << '\n';
    ll ans = qpow(c, ans1, n) % n;
    cout << ans << '\n';
    return 0;
}