#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6;
char str1[maxn],str2[maxn];
int nexts[maxn],ans[maxn];
int cnt=0;

void getnextarr(char* str)
{
	/*
	a  b  b  a  a  b  a  b
       -1  0  0  0  1  1  2  1
	*/
	int n=strlen(str);
	nexts[0]=-1,nexts[1]=0;
	for (int i=2;i<=n;i++)
	{
		int k=i-1;
		while (1){
			if (nexts[k]==-1 || str[i-1]==str[nexts[k]]) 
			{
				nexts[i]=nexts[k]+1;
				break;
			}
			else k=nexts[k];
		}
	}
	return ;
}

void kmp()
{
	int len1=strlen(str1);
	int len2=strlen(str2);
	int i=0,j=0;
	getnextarr(str2);
	while (i<len1)
	{
		if (str1[i]==str2[j]){
		       	if (j!=len2-1) i++,j++;
			else {
				ans[cnt++]=i-j+1;
				j=nexts[j];
			}
		}
		else if (nexts[j]==-1) i++;
		else j=nexts[j];
	}
	for (int t=0;t<cnt;t++) printf("%d\n",ans[t]);
	for (int t=0;t<len2;t++) {
		 printf("%d ",nexts[t+1]);
	}
	return ;
}

int main()
{
	scanf("%s %s",str1,str2);
	kmp();
	return 0;
}

