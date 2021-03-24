#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main()
{
	ll n,n2;
    int cnt=0;
	cin>>n;
	n2=n*2;
	for (int i=1;1LL*i*i<=n2;i++){
		if (n2%i==0){
			if ((n2/i+1-i)%2==0) cnt++;
			if ((n2/(n2/i)+1-(n2/i))%2==0) cnt++;
			if (1LL*i*i==n2 && ((n2/i+1-i)%2==0)) cnt--;
		}
	}
	cout<<cnt;
	return 0;
}