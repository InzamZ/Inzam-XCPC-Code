#include <bits/stdc++.h>
using namespace std;
int cnt1 = 0, cnt2 = 0;
int main()
{
    int t, n;
    scanf ("%d ", &t);
    while (t--) {
        int ans = 0;
        char ch = getchar();
        cnt1 = 0, cnt2 = 0;
        while (ch != '\n') {
            if (ch == '(')
                cnt1++;
            else if (ch == '[')
                cnt2++;
            else if (ch == ')' && cnt1)
                ans++, cnt1--;
            else if (ch == ']' && cnt2)
                ans++, cnt2--;
            ch = getchar();
        }
        cout << ans << endl;
    }
    return 0;
}