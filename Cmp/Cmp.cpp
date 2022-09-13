#include<bits/stdc++.h>
using namespace std;
int main(){
	long long i;
	for(i = 1;;i++){
		printf("Data %lld: ",i);
		system("./Data.out");
		system("./Std.out");
		system("./My.out");
		if(system("diff std.output my.output")){
			printf("WA\n");
			return 0;
		}
		else printf("AC\n");
	}
	return 0;
}
