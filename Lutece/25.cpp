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
        memset(imap, 0, sizeof(imap));
        bool fl = 0;
        int cnt = 1;
        for (int i = 1; i <= T; ++i) {
            string s1;
            getline(std::cin, s1);
            if (s1.length() < 8)
                imap[cnt][fl] = 1;
            else {
                string s2 = s1.substr(s1.size() - 8);
                if (s2 == " no good")
                    imap[cnt][fl] = 2;
                else
                    imap[cnt][fl] = 1;
            }
            if (fl)
                ++cnt;
            fl = !fl;
        }
        cnt = (T + 1) / 2;
        for (int i = 1; i <= cnt; ++i)
            printf("%d ", i);
        printf("Score\n");
        int score = 0;
        for (int i = 1; i <= cnt; ++i) {
            if (imap[i][0] == 1) {
                printf("O ");
                score++;
            }
            if (imap[i][0] == 2)
                printf("X ");
            if (imap[i][0] == 0)
                printf("- ");
        }
        printf("%d\n", score);
        score = 0;
        for (int i = 1; i <= cnt; ++i) {
            if (imap[i][1] == 1) {
                printf("O ");
                score++;
            }
            if (imap[i][1] == 2)
                printf("X ");
            if (imap[i][1] == 0)
                printf("- ");
        }
        printf("%d", score);
        scanf("%d ", &T);
        if (T == 0)
            break;
        putchar('\n');
    }
    return 0;
}