#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,ans=1000000007;
bool vis[100010];
vector<int>v;
//vector<int>ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int l = -1, r = n - 1;
	for (int i = 2; i < 50010; ++i)
	{
		if (vis[i] == 0) v.push_back(i);
		for (int j = i * 2; j< 50010; ++j)
		{
			vis[j] = 1;
		}
	}
	for (int i = 0 ; i < v.size(); ++i)
	{
		if (n % v[i] == 0)
		{
			l = n / v[i];
			break;
		}
	}
	if (l == -1) 
	{
		printf("-1\n");
		return 0;
	}
	else 
	{
		for (int i = l + 1; i < n; ++i)
		{
			if (vis[i] == 1)
			{
				for (int j = 0; v[j] < i && j < v.size();++j)
				{
					if (i % v[j] == 0 && vis[i/v[j]] == 0)
					{
						ans = min(ans, i - i / v[j] + 1);
						//printf("v[j] : %d    ans : %d\n",v[j],ans);	
					}
				}
			}
		}
		if (ans == 1000000007) 
		{
			printf("-1\n");
		}
		else 
		{
			printf("%d\n",ans);
		}
	}
	return 0;
} 
