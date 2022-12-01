#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, ans, cur, cnto = 0, cntw = 0;
string s[1000010];
bool bego,begwo,endow,endo,oow = 0,woo = 0;
int bcnto,bcntwo,ecntow,ecnto;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	bego = begwo = endow = endo = 0;
	cin >> n;
	for (int i = 1;i <= n; ++i)
	{
		bego = begwo = endow = endo = 0;
		cin >> s[i];
		int len = s[i].length();
		if (s[i].length() == 1)
		{
			if (s[i][0]=='o') ++cnto;
			else ++cntw;
		}
		else 
		{
			if (s[i][0] == 'o') bego = 1;
			if (s[i][0] == 'w' && s[i][1] == 'o') begwo = 1;
			
			if (s[i][len-1] == 'o') endo = 1;
			if (s[i][len-2] == 'o' && s[i][len-1] == 'w') endow = 1;
		}
		for (int j = 0;j < len - 2;++j)
		{
			if (s[i][j] == 'o' && s[i][j + 1] == 'w' && s[i][j + 2] == 'o') ++ans;
		}
		if (!oow && bego && endow)
		{
			oow = 1;
			bcnto++;
			ecntow++;
		}
		else if (oow && bego && endow)
		{
			++ans;
		}
		
		else if (!woo && begwo && endo)
		{
			oow = 1;
			bcntwo++;
			ecnto++;
		}
		else if (woo && begwo && endo)
		{
			++ans;
		}
		else {
			if (begwo) ++bcntwo;
			if (bego) ++bcnto;
			if (endo) ++ecnto;
			if (endow) ++ecntow;
		}
		int tmp = ans,tmpbo = bcnto,tmpbwo = bcntwo,tmpeow = ecntow,tmpeo = ecnto;
		if (oow) 
		{
			if (tmpbo != 1 || tmpeow != 1) 
			{
				tmp += min(tmpbo,tmpeow);
				tmpbo -= min(tmpbo,tmpeow);
				tmpeow -= min(tmpbo,tmpeow);
			}
		}
		else 
		{
			tmp += min(tmpbo,tmpbwo);
			tmpbo -= min(tmpbo,tmpbwo);
			tmpbwo -= min(tmpbo,tmpbwo);
		}
		if (woo) 
		{
			if (tmpbwo != 1 || tmpeo != 1) 
			{
				tmp += min(tmpbwo,tmpeo);
				tmpbwo -= min(tmpbwo,tmpeo);
				tmpeo -= min(tmpbwo,tmpeo);
			}
		}
		else 
		{
			tmp += min(tmpbwo,tmpeo);
			tmpbwo -= min(tmpbwo,tmpeo);
			tmpeo -= min(tmpbwo,tmpeo);
		}
		if (max(tmpeo,tmpbo) > 1) tmp += min(cntw,min(tmpeo-1,tmpbo-1));
		if (max(tmpeow,tmpbwo) > 1) tmp += min(cnto,min(tmpeow-1,tmpbwo-1));
		printf("%d\n",tmp);
	}
	return 0;
} 
