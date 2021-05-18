#include <iostream>
#include <ctime>
using namespace std;

#define RMAXN 1000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i;
    freopen("input.in","w",stdout);
    srand(time(NULL));
    int num1=rand()% (int)(RMAXN)+1,num2=rand()% (int)(RMAXN)+1;
    num1=3e5;num2=10;
    cout<<num1<<' '<<num2<<'\n';
    for (i=1;i<=num1;++i) 
    {
        cout<<i<<endl;
    }
    for (int i=1;i<=num2;i++) {
        // int op=rand()% (int)(3)+1;
        int x=rand()% (int)(num1)+1,y=rand()% (int)(num1)+1;
        // while (x==y) y=rand()% (int)(num1)+1;
        if (x>y) swap(x,y);
        cout<<x<<' '<<y<<'\n';
    }
    fclose(stdin);
    return 0;
}