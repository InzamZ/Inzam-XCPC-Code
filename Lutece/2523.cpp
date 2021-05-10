#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
using ll = long long;
const ll mod = 1e9+7;
struct node {
    ll len,val;
    node(ll a,ll b):len(a),val(b) {}
};
stack<node>mx;
stack<node>mn;
ll mxsum=0,mnsum=0;
ll n,a,ans=0;

ll qpow(ll a,ll b)
{
    ll res=a,ans=1;
    while(b>0){
        if (b & 1ll) ans=ans*res%mod;
        res=res*res%mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n ;
    for (int i = 1; i <= n; ++i) {
        int len=1;
        cin >> a;
        while(!mx.empty() && mx.top().val>=a)
        {
            len+=mx.top().len;
            mxsum-=(mx.top().len*mx.top().val);
            mxsum=(mxsum+mod)%mod;
            mx.pop();
        }
        mx.push(node(len,a));
        mxsum+=(len*a);
        mxsum=(mxsum+mod)%mod;
        len=1;
        while(!mn.empty() && mn.top().val<=a)
        {
            len+=mn.top().len;
            mnsum-=(mn.top().len*mn.top().val);
            mnsum=(mnsum+mod)%mod;
            mn.pop();
        }
        mn.push(node(len,a));
        mnsum+=(len*a);
        mnsum=(mnsum+mod)%mod;
        ans=(ans+mxsum+mnsum)%mod;
    }
    cout<<((ans+mod)%mod)*qpow((n+1)*n%mod,mod-2)%mod;
    return 0;
}
