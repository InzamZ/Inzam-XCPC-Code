#include <iostream>
using namespace std;
int main()
{
    int n, s, d, a, b;
    bool flag = false;
    cin >> n >> s >> d;
    while (n--) {
        cin >> a >> b;
        if (a < s && b > d) {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}