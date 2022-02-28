#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int cnt[4];

int main()
{
    int T = 1, n, ans = 0;
    string a, b, c, d, s1, s2, s3, s4;
    // scanf("%d",&T);
    while (T--) {
        cin >> s1 >> s2 >> s3 >> s4;
        if (s1 == "H" || s2 == "H" || s3 == "H" || s4 == "H")
            ++cnt[0];
        if (s1 == "HR" || s2 == "HR" || s3 == "HR" || s4 == "HR")
            ++cnt[1];
        if (s1 == "2B" || s2 == "2B" || s3 == "2B" || s4 == "2B")
            ++cnt[2];
        if (s1 == "3B" || s2 == "3B" || s3 == "3B" || s4 == "3B")
            ++cnt[3];
        if (cnt[0] && cnt[1] && cnt[2] && cnt[3])
            printf("Yse\n");
        else
            printf("No\n");
    }
    return 0;
}