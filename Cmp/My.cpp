#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int a[200005];
set<int>aa;
int main(){
    freopen("./data.input", "r", stdin);
    freopen("./my.output", "w", stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		aa.insert(a[i]);
	}
	// sort(a,a+n);
	n=aa.size();
	set<int>::iterator it; 
	// for(it=aa.begin();it!=aa.end();it++)printf("%d ",*it);
	int p=0;
	for(it=aa.begin();it!=aa.end();it++){
		if(*it!=0&&*it!=1){
			break;
		}
		p=*it;
	}
	// for(int i=0;i<n;i++){
	// 	if(a[i]!=0){
	// 		p=i;
	// 		break;
	// 	}
	// }
	bool ans=false;
	int b;
	// if(p==n-1)b=a[p];
	// else if(a[p]==a[p+1])b=a[p];
	// else b=a[1+p]-a[p+0];
	// for(int i=p+1;i<n-1;i++)
	// 	if(a[i+1]-a[i]>1)b=min(b,a[i+1]-a[i]);
	b=*it-p;
	int ttmp=*it;
	if(it!=aa.end())it++;
	for(;it!=aa.end();it++){
		// printf("%d %d  ",*it,*it-ttmp);
		if(*it-ttmp>1)b=min(b,*it-ttmp);
		ttmp=*it;
	}
	printf("%d\n",b);
	for(int i=b;i>1;i--){
		if(b%i&&i!=2)continue;
		// int tmp=a[0]%i;
		int tmp=(*aa.begin())%i;
		// for(int k=1;k<n;k++){
		// 	if(a[k]%i!=tmp)break;
		// 	if(k==n-1&&a[k]%i==tmp)ans=true;
		// }
		set<int>::iterator iit;
		for(iit=aa.begin();iit!=aa.end();iit++){
			if(*iit%i!=tmp)break;
		} 
		if(iit==aa.end())ans=true;
		if(ans)break;
	}
	if(ans)printf("1\n");
	else printf("2\n");
	return 0;
}