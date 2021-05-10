#include <iostream>
#include <ctime>
using namespace std;

#define RMAXN 1000

int main()
{
    freopen("input.in","w",stdout);
    srand(time(NULL));
    int num1=rand()% (int)(RMAXN)+1,num2=rand()% (int)(5)+1;
    cout<<num1<<' '<<num2<<endl;
    for (int i=1;i<=num1;i++) {
        cout<<i<<endl;
    }
    for (int i=1;i<=num2;i++) {
        int op=rand()% (int)(3)+1;
        int x=rand()% (int)(num1)+1,y=rand()% (int)(num1)+1;
        while (x==y) y=rand()% (int)(num1)+1;
        cout<<op<<' '<<x<<' '<<y<<endl;
    }
    fclose(stdin);
    return 0;
}