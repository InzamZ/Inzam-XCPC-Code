#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int maxm = 1010;
using ll = long long;

#define now (i%2)
#define last ((i+1)%2)
char s[maxn];
ll dp[maxn][maxm];

struct bigint {
    const int base = 1e8;
    const int width = 8;
    vector<int>s;
    ll sum = -1;

    bigint (ll num = 0)
    {
        *this = num;
    }

    bigint operator= (ll num)
    {
        s.clear();
        do {
            s.push_back(num % base);
            num /= base;
        }
        while (num > 0);
        return *this;
    }

    bigint operator= (const bigint A)
    {
        s.clear();
        for (int i = 0; i < A.s.size(); ++i)
            s.push_back(A.s[i]);
        return *this;
    }

    bigint operator+ (const bigint &A)
    {
        bigint c;
        c.s.clear();
        for (int i = 0, g = 0;; ++i) {
            if (g == 0 && i >= s.size() && i >= A.s.size())
                break;
            int x = g;
            if (i < s.size())
                x += s[i];
            if (i < A.s.size())
                x += A.s[i];
            c.s.push_back(x % base);
            g = x / base;
        }
        return c;
    }

    ll getnum()
    {
        if (sum != -1)
            return sum;
        ll ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int x = s[i];
            while (x) {
                ans += (x % 10);
                x /= 10;
            }
        }
        sum = ans;
        return ans;
    }
} val[maxn][maxn];

ostream &operator << (ostream &out, const bigint &A)
{
    out << A.s.back();
    for (int i = A.s.size() - 2; i >= 0; --i) {
        char buf[20];
        sprintf(buf, "%08d", A.s[i]);
        for (int j = 0; j < strlen(buf); ++j)
            out << buf[j];
    }
    return out;
}

int main()
{
    int n, m, t;
    ll ans = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        ans = 0;
        m = min(m + 1, n);
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                dp[i][j] = 0;
        scanf("%s", s);
        for (int j = 0; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                if (k >= 1)
                    val[j][k] = val[j][k - 1] + val[j][k - 1] + (s[k] - '0');
                else
                    val[j][k] = (s[k] - '0');
                val[j][k].sum = -1;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = i - 1; j < n; ++j) {
                if (i == 1)
                    dp[j][1] = val[0][j].getnum();
                else
                    for (int k = i - 2; k < j; ++k)
                        dp[j][i] = max(dp[j][i], dp[k][i - 1] + val[k + 1][j].getnum());
            }
        }
        for (int i = 1; i <= m; ++i)
            ans = max(ans, dp[n - 1][i]);
        printf("%lld\n", ans);
    }
    return 0;
}