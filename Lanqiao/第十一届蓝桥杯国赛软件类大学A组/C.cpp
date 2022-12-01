#include<cstdio>
#include<iostream>
using namespace std;

long long T,gb,mb,kb,bb,cur,typ,bas;
char s[100025];

int main()
{
	gb = mb = kb = bb = 0;
	cin >> T;
	while (T--)
	{
		cur = 0;
		char ch = getchar();
		while (ch == '\n' || ch == ' ') ch = getchar(); 
		while (ch != '\n') 
		{
			s[cur++] = ch;
			ch = getchar();
		}
		int i = 0;
		if (cur > 3 && s[0] == 'i' && s[1] == 'n' && s[2] == 't' && s[3] == ' ') typ = 1, i = 4, bas = 4;
		if (cur > 3 && s[0] == 'i' && s[1] == 'n' && s[2] == 't' && s[3] == '[') typ = 11, i = 6, bas = 4;
		if (cur > 4 && s[0] == 'l' && s[1] == 'o' && s[2] == 'n' && s[3] == 'g' && s[4] == ' ') typ = 2, i = 5, bas = 8;
		if (cur > 4 && s[0] == 'l' && s[1] == 'o' && s[2] == 'n' && s[3] == 'g' && s[4] == '[') typ = 12, i = 7, bas = 8;
		if (cur > 5 && s[0] == 'S' && s[1] == 't' && s[2] == 'r' && s[3] == 'i' && s[4] == 'n' && s[5] == 'g') typ = 3, i = 7, bas = 4;
		int cnt = -1;
		//printf("%d\n",typ);
		if (typ < 10) for ( i; i < cur; ++i)
		{
			if (typ < 3) {
				if (s[i] == ';' || s[i] == ',') bb += bas;
			}
			else 
			{
				//printf("%lld\n",bb);
				if (cnt != -1 && s[i] != '"') cnt++;
				else if (cnt != -1 && s[i] == '"') 
				{
					bb += cnt;
					cnt = -1;
				}
				else if (cnt == -1 && s[i] == '"') cnt = 0;
			}
			if (bb >= 1024) {
				kb += bb /1024;
				bb %= 1024;
			} 
			if (kb >= 1024) {
				mb += kb /1024;
				kb %= 1024;
			} 
			if (mb >= 1024) {
				gb += mb /1024;
				mb %= 1024;
			} 
		}
		else 
		{
			for (i; i < cur ;++i)
			{
				if (s[i] == '[')
				{
					++i;
					cnt = 0;
					while(s[i]<='9' && s[i]>='0')
					{
						cnt = cnt *10 + (s[i] - '0');
						++i;
					}
					printf("%d\n",cnt);
					bb += cnt * bas;
					if (bb >= 1024) {
						kb += bb /1024;
						bb %= 1024;
					} 
					if (kb >= 1024) {
						mb += kb /1024;
						kb %= 1024;
					} 
					if (mb >= 1024) {
						gb += mb /1024;
						mb %= 1024;
					} 
				}
			}
		}
	}
	/*if (!gb && !mb && !kb && !bb) 
	{
		printf("0B\n");
		return 0;
	}*/
	if (gb != 0) printf("%lldGB",gb);
	if (mb != 0) printf("%lldMB",mb);
	if (kb != 0) printf("%lldKB",kb);
	if (bb != 0) printf("%lldB",bb);
	return 0;
} 
