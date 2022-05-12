//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0;

class FenwickTree {
public:
    int n, ta[maxn];
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int i, int val) {
        int x = i;
        while (i <= n) {
            ta[i] += val;
            i += lowbit(i);
        }
    }
    int getsum(int i) {
        int res = 0, x = i;
        while (i > 0) {
            res += ta[i];
            i -= lowbit(i);
        }
        return res;
    }
};
