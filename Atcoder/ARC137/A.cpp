#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("out.txt" , "w", stdout);

const int maxn = 1e5 + 10;
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
template<typename T>
inline T read(T &x)
{
    x = 0;
    T w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-')
            w = -1;        // 判断是否为负
        ch = nc();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = nc();  // 继续读入
    }
    x *= w;
    return x;  // 数字 * 正负号 = 实际数值
}

template<typename T>
inline void write(T x)
{
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    }
    while (x);
    while (top)
        putchar(sta[--top] + 48);  // 48 是 '0'
}
#endif
int T = 1, n;
ll ans = 0;
int main()
{
    // FIO;
    // read(T);
    ll l, r;
    while (T--) {
        ans = 0;
        read(l);
        read(r);
        if (l == 1 || __gcd(r, l) == 1)
            ans = r - l;
        else if (r % l == 0)
            ans = r - 1 - l;
        else {
            ans = 1;
            for (ll i = r - l; i >= 1; --i) {
                if (__gcd(i, l) == 1 && __gcd(i, r) == 1) {
                    ans = i; break;
                }
                if (i != r - l && __gcd(i, l + 1) == 1 && __gcd(i, r) == 1) {
                    ans = i; break;
                }
                if (i != r - l && __gcd(i, l) == 1 && __gcd(i, r - 1) == 1) {
                    ans = i; break;
                }
                if (i < r - l - 1 && __gcd(i, l + 2) == 1 && __gcd(i, r) == 1) {
                    ans = i; break;
                }
                if (i < r - l - 1 && __gcd(i, l) == 1 && __gcd(i, r - 2) == 1) {
                    ans = i; break;
                }
                if (i < r - l - 1 && __gcd(i, l + 1) == 1 && __gcd(i, r - 1) == 1) {
                    ans = i; break;
                }
            }
        }
        printf("%lld", ans); putchar('\n');
    }
    return 0;
}