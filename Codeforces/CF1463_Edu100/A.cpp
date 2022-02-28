//InzamZ

#include<cstdio>
#include<iostream>
using namespace std;
int num[10];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, num;
        cin >> a >> b >> c;
        num = a + b + c;
        if (num % 9 == 0 && num / 9 <= a && num / 9 <= b && num / 9 <= c )
            cout << "YES";
        else
            cout << "NO";
        putchar(10);
    }
    return 0;
}