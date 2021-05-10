#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int len,m;
char s[1010];
int bin[20],Log[1010];
int ST[1010][20];

int Min(int a,int b)
{
	return s[a]<=s[b]?a:b;
}

void getST()
{
	len=strlen(s);
	memset(ST,0,sizeof(ST));
	for (int j=0;j<=11;j++){
		for (int i=0;i+bin[j]-1<len;i++){
			if (j==0) ST[i][j]=i;
			else ST[i][j]=Min(ST[i][j-1],ST[i+bin[j-1]][j-1]);
		}
	}
}

int STsearch(int x,int y)
{
	if (x==y) return x;
	int t=Log[y-x+1];
	return Min(ST[x][t],ST[y-bin[t]+1][t]);
}

int main()
{
	Log[0]=-1;
	for (int i=1,cnt=0;cnt<=12;cnt++,i<<=1) bin[cnt]=i;
	for (int i=1;i<1010;i++) Log[i]=Log[i/2]+1;
	while (scanf("%s %d",s,&m)!=EOF)
	{
		bool flag=true;
		int l=0,r=m;
		getST();
		if (m>=len) {
			putchar('0');
			putchar('\n');
			continue;
		}
		for (int i=1;i<=len-m;i++){
			l=STsearch(l,r);
			if (flag && s[l]!='0') flag=false;
			if (!flag) putchar(s[l]);
			r++;
			l++;
		}
		if (flag) putchar('0');
		putchar(10);
		memset(s,0,sizeof(s));
	}
	return 0;
}
