//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n;
char s1[maxn], s2[maxn];
int cnt10, cnt11, cnt20, cnt21, cnt, ans;

int main()
{
    scanf("%d", &T);
    while (T--) {
        int len;
        scanf("%d", &len);
        scanf("%s%s", s1, s2);
        cnt = cnt10 = cnt11 = cnt20 = cnt21 = 0;
        for (int j = 0; j < len; ++j) {
            if (s1[j] == '0') ++cnt10;
            else ++cnt11;
            if (s2[j] == '0') ++cnt20;
            else ++cnt21;
        }
        if (cnt10 == cnt20 && cnt11 - 1 != cnt20) {
            for (int j = 0; j < len; ++j) {
                if (s1[j] != s2[j]) ++cnt;
            }
            if (cnt % 2 == 0) ans = cnt;
            else ans = -1;
        } else if (cnt10 != cnt20 && cnt11 - 1 == cnt20) {
            int k = 0;
            for (k = 0; k < len; ++k) {
                if (s2[k] == '1' && s1[k] == '1') break;
            }
            if (k == len) for (k = 0; k < len; ++k) {
                    if (s1[k] == '1') break;
                }
            for (int j = 0; j < len; ++j) {
                if (j == k) {
                    if (s1[j] != s2[j]) ++cnt;
                } else {
                    if (s1[j] == s2[j]) ++cnt;
                }
            }
            if (cnt % 2 == 0) ans = cnt + 1;
            else ans = -1;
        } else if (cnt10 == cnt20 && cnt11 - 1 == cnt20) {
            for (int j = 0; j < len; ++j) {
                if (s1[j] != s2[j]) ++cnt;
            }
            if (cnt % 2 == 0) ans = cnt;
            else ans = 1e9;
            int k = 0;
            cnt = 0;
            for (k = 0; k < len; ++k) {
                if (s2[k] == '1' && s1[k] == '1') break;
            }
            if (k == len) for (k = 0; k < len; ++k) {
                    if (s1[k] == '1') break;
                }
            for (int j = 0; j < len; ++j) {
                if (j == k) {
                    if (s1[j] != s2[j]) ++cnt;
                } else {
                    if (s1[j] == s2[j]) ++cnt;
                }
            }
            if (cnt % 2 == 0) ans = min(cnt + 1, ans);
            if (ans == 1e9) ans = -1;
        } else {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}