#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, num;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%d", &num);
        if (num == 1)
            cout << 0 << endl;
        else if (num == 2)
            cout << 1 << endl;
        else if (num == 3)
            cout << 2 << endl;
        else if (num % 2 == 0)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    return 0;
}
