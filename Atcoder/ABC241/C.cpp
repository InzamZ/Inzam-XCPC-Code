//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 1e3 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

char imap[maxn][maxn];
int l, r, n;

// bool icheck(int i, int j)
// {
//     int cnt = 0;
//     l = max(i - 5, 0);
//     r = min(n - 1, i + 5);
//     for (int k = l; k <= r; ++k) {
//         if (imap[k][j] == '#')
//             cnt++;
//         if (k - 6 >= l && imap[k - 6][j] == '#')
//             --cnt;
//         if (cnt >= 4)
//             return true;
//     }
//     cnt = 0;
//     l = max(j - 5, 0);
//     r = min(n - 1, j + 5);
//     for (int k = l; k <= r; ++k) {
//         if (imap[i][k] == '#')
//             cnt++;
//         if (k - 6 >= l && imap[i][k - 6] == '#')
//             --cnt;
//         if (cnt >= 4)
//             return true;
//     }
//     for (int )
// }

int main()
{
    int T = 1, ans = 0, cnt = 0;
    // T = _read();
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%s", imap[i]);
        for (int i = 0; i < n && !ans; ++i) {
            cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (imap[i][j] == '#')
                    cnt++;
                if (j >= 6 && imap[i][j - 6] == '#')
                    cnt--;
                if (cnt >= 4) {
                    ans = 1;
                    break;
                }
            }
        }
        if (!ans) {
            for (int i = 0; i < n && !ans; ++i) {
                cnt = 0;
                for (int j = 0; j < n; ++j) {
                    if (imap[j][i] == '#')
                        cnt++;
                    if (j >= 6 && imap[j - 6][i] == '#')
                        cnt--;
                    if (cnt >= 4) {
                        ans = 1;
                        break;
                    }
                }
            }
        }
        if (!ans) {
            for (int i = 0; i < n - 5 && !ans; ++i) {
                cnt = 0;
                int r = 0, c = i;
                for (int j = 0; !ans; ++j) {
                    if (r + j >= n || c + j >= n)
                        break;
                    if (imap[r + j][c + j] == '#')
                        ++cnt;
                    if (j >= 6 && imap[r + j - 6][c + j - 6] == '#')
                        --cnt;
                    if (cnt >= 4) {
                        ans = 1;
                        break;
                    }
                }
                r = i, c = 0;
                cnt = 0;
                for (int j = 0; !ans; ++j) {
                    if (r + j >= n || c + j >= n)
                        break;
                    if (imap[r + j][c + j] == '#')
                        ++cnt;
                    if (j >= 6 && imap[r + j - 6][c + j - 6] == '#')
                        --cnt;
                    if (cnt >= 4) {
                        ans = 1;
                        break;
                    }
                }
            }
        }
        if (!ans) {
            for (int i = 5; i < n && !ans; ++i) {
                cnt = 0;
                int r = 0, c = i;
                for (int j = 0; !ans; ++j) {
                    if (r + j >= n || c - j < 0 )
                        break;
                    if (imap[r + j][c - j] == '#')
                        ++cnt;
                    if (j >= 6 && imap[r + j - 6][c - j + 6] == '#')
                        --cnt;
                    if (cnt >= 4) {
                        ans = 1;
                        break;
                    }
                }
            }
            for (int i = 0; i < n - 5 && !ans; ++i) {
                cnt = 0;
                int r = 0, c = i;
                r = i, c = n - 1;
                for (int j = 0; !ans; ++j) {
                    if (r + j >= n || c - j < 0)
                        break;
                    if (imap[r + j][c - j] == '#')
                        ++cnt;
                    if (j >= 6 && imap[r + j - 6][c - j + 6] == '#')
                        --cnt;
                    if (cnt >= 4) {
                        ans = 1;
                        break;
                    }
                }
            }
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}