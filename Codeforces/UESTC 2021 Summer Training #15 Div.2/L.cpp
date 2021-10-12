//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

int c[15];

int main()
{
    int T = 1, n, ans = 0;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        for (int i = 0; i <= 9; ++i) {
            scanf("%d", &c[i]);
            ans += c[i];
        }
        if (c[0] >= 2 && ans != c[0]) {
            c[0] -= 2;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("00\n");
        }
        else if (c[2] >= 1 && c[0] >= 1) {
            c[2]--; c[0]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("20\n");
        }
        else if (c[4] >= 1 && c[0] >= 1) {
            c[4]--; c[0]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("40\n");
        }
        else if (c[6] >= 1 && c[0] >= 1) {
            c[6]--; c[0]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("60\n");
        }
        else if (c[8] >= 1 && c[0] >= 1) {
            c[8]--; c[0]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("80\n");
        }
        else if (c[1] >= 1 && c[2] >= 1) {
            c[2]--; c[1]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("12\n");
        }
        else if (c[3] >= 1 && c[2] >= 1) {
            c[2]--; c[3]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("32\n");
        }
        else if (c[2] >= 1 && c[4] >= 1) {
            c[2]--; c[4]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("24\n");
        }
        else if (c[4] >= 2) {
            c[4] -= 2;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("44\n");
        }
        else if (c[5] >= 1 && c[2] >= 1) {
            c[2]--; c[5]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("52\n");
        }
        else if (c[1] >= 1 && c[6] >= 1) {
            c[1]--; c[6]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("16\n");
        }
        else if (c[3] >= 1 && c[6] >= 1) {
            c[3]--; c[6]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("36\n");
        }
        else if (c[6] >= 1 && c[4] >= 1) {
            c[4]--; c[6]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("64\n");
        }
        else if (c[5] >= 1 && c[6] >= 1) {
            c[5]--; c[6]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("56\n");
        }
        else if (c[7] >= 1 && c[2] >= 1) {
            c[2]--; c[7]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("72\n");
        }
        else if (c[7] >= 1 && c[6] >= 1) {
            c[6]--; c[7]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("76\n");
        }
        else if (c[2] >= 1 && c[8] >= 1) {
            c[2]--; c[8]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("28\n");
        }
        else if (c[8] >= 1 && c[4] >= 1) {
            c[4]--; c[8]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("84\n");
        }
        else if (c[6] >= 1 && c[8] >= 1) {
            c[8]--; c[6]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("68\n");
        }
        else if (c[8] >= 2) {
            c[8] -= 2;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("88\n");
        }
        else if (c[9] >= 1 && c[2] >= 1) {
            c[2]--; c[9]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("92\n");
        }
        else if (c[9] >= 1 && c[6] >= 1) {
            c[9]--; c[6]--;
            for (int i = 9; i >= 0; --i) {
                while (c[i]) {
                    putchar(i + '0');
                    c[i]--;
                }
            }
            printf("96\n");
        }
        else if (c[8] >= 1)
            printf("8\n");
        else if (c[4] >= 1)
            printf("4\n");
        else if (c[0] >= 1)
            printf("0\n");
        else
            printf("-1\n");
    }
    return 0;
}