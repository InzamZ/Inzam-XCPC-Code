//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;
int imap[20][2];
int main()
{
    scanf("%d ", &T);
    while (T != 0) {
        string s1;
        int cnt1 = 0, cnt2 = 0;
        cin >> s1;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] == 'R')
                ++cnt1;
            if (s1[i] == 'Y')
                ++cnt2;
        }
        if (s1[s1.length() - 1] == 'B') {
            if (cnt1 == 7) {
                printf("Red\n");
                ++ans;
            }
            else
                printf("Yellow\n");
        }
        if (s1[s1.length() - 1] == 'L') {
            if (cnt2 == 7) {
                printf("Yellow\n");
                ++ans;
            }
            else
                printf("Red\n");
        }
        scanf("%d ", &T);
        if (T == 0)
            break;
        putchar('\n');
    }
    return 0;
}