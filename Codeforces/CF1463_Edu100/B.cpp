//InzamZ

#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
ll num[10000], bin[100];
int main()
{
    int t;
    cin >> t;
    bin[0] = 1;
    for (int i = 1; i <= 30; i++)
        bin[i] = bin[i - 1] * 2;
    while (t--) {
        int n, sum = 0, flag;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> num[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 29; j++) {
                if (bin[j] * 2 >= num[i]) {
                    cout << bin[j] << ' ';
                    break;
                }
            }
        }
        putchar(10);
    }
    return 0;
}