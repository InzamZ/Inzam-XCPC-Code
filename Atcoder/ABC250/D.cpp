//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 1e6;
const int maxb = 110;
int T = 1, n, m, x, ans = 0;

bool isprime[maxn];
vector<int>prime;
vector<int>prime3;

__int128_t tmp;

signed main()
{
    FIO;
    // cin >> T;
    forr(i, 2, maxn) {
        if (i >= 1000000)
            break;
        if (isprime[i])
            continue;
        prime.push_back(i);
        prime3.push_back(1ll * i * i * i);
        for (int j = i * 2; j < maxn; j += i)
            isprime[j] = true;
    }
    while (T--) {
        ans = 0;
        cin >> n;
        for (int j = 0; j < prime.size(); j++) {
            tmp = prime[j];
            tmp *= tmp;
            tmp *= tmp;
            if (j != prime.size() - 1 && tmp > n)
                break;
            for (int k = j + 1; k < prime.size(); ++k)
                if (prime3[k] * prime[j] <= n)
                    ++ans;
                else
                    break;
        }
        cout << ans << '\n';
    }
    return 0;
}