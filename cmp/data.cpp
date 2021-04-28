#include <iostream>
#include <ctime>
using namespace std;

#define RMAXN 1000

int main()
{
    freopen("in","w",stdout);
    srand(time(NULL));
    int num1=rand()% (int)(RMAXN)+1,num2=rand()% (int)(5)+1,num3=rand()% (int)(RMAXN)+1;
    cout<<num1+1<<' '<<num2+1<<' '<<num3+1<<endl;
    for (int i=1;i<=num1;i++) {
        cout<<rand()% (int)(RMAXN)+1<<' '<<rand()% (int)(RMAXN)+1<<' '<<rand()% (int)(RMAXN)+1<<endl;
    }
    for (int i=1;i<=num2;i++) {
        cout<<rand()% (int)(RMAXN)+1<<' '<<rand()% (int)(RMAXN)+1<<' '<<rand()% (int)(RMAXN)+1<<endl;
    }
    fclose(stdin);
    return 0;
}