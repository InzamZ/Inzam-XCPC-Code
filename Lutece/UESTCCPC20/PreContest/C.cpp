//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;

int a[maxn], n;

int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int val)
{
    while (i <= n) {
        a[i] += val;
        i += lowbit(i);
    }
}

int getsum(int i)
{
    int res = 0;
    while (i > 0) {
        res += a[i];
        i -= lowbit(i);
    }
    return res;
}

char s[10];
int l, r, x;

struct inode {
    int l, r, x;
    inode(int l, int r, int x) : l(l), r(r), x(x) {}
};
stack<inode>st;
multiset<int>S;

int main()
{
    scanf("%d %d", &n, &T);
    while (T--) {
        ans = 0;
        scanf("%s", s);
        if (s[0] == 'A') {
            scanf("%d %d %d", &l, &r, &x);
            if (x == 0)
                continue;
            st.push({l, r, x});
            S.insert(l - 1);
            S.insert(r);
            update(l, x);
            update(r + 1, -x);
        }
        else if (s[0] == 'B') {
            scanf("%d", &x);
            

        }
        else if (s[0] == 'C') {
            auto tmp = st.top();
            st.pop();
            S.erase(S.find(tmp.l - 1));
            S.erase(S.find(tmp.r));
        }
    }
    return 0;
}