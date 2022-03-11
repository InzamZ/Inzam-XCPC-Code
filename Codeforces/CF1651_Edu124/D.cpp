#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);

const int maxn = 2e5 + 10;
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

struct inode {
    int x, y, id=0;

    inode () : x(0), y(0) {}
    inode (int _x, int _y) : x(_x), y(_y) {}

    bool operator < (inode a)
    {
        return x == a.x ? y < a.y : x < a.x;
    }
} cur, ans[maxn];

bool vis[maxn];
int dire[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
vector<inode>p;
queue<inode>q;

int main()
{
    // FIO;
    // read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; ++i) {
            read(cur.x);
            read(cur.y);
            cur.id = i;
            p.push_back(cur);
        }
        sort(p.begin(), p.end());
        for (auto it : p) {
            bool flag = 0;
            for (int i = 0; !flag &&  i < 4; ++i) {
                int x = it.x + dire[i][0], y = it.y + dire[i][1];
                auto tmp = lower_bound(p.begin(), p.end(), inode(x, y));
                if (tmp->x != x || tmp->y != y) {
                    flag = 1;
                    ans[it.id].x = x;
                    ans[it.id].y = y;
                }
            }
            if (flag) {
                q.push(it);
                vis[it.id] = 1;
            }
        }
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = it.x + dire[i][0], y = it.y + dire[i][1];
                auto tmp = lower_bound(p.begin(), p.end(), inode(x, y));
                if (tmp->x == x && tmp->y == y) {
                    if (!vis[tmp->id]) {
                        q.push(*tmp);
                        vis[tmp->id] = 1;
                        ans[tmp->id].x = ans[it.id].x;
                        ans[tmp->id].y = ans[it.id].y;
                    }
                    else {
                        int cnt1 = abs(x - ans[tmp->id].x) + abs(y - ans[tmp->id].y);
                        int cnt2 = abs(x - ans[it.id].x) + abs(y - ans[it.id].y);
                        if (cnt1 > cnt2) {
                            ans[tmp->id].x = ans[it.id].x;
                            ans[tmp->id].y = ans[it.id].y;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            write(ans[i].x); putchar(' ');
            write(ans[i].y); putchar('\n');
        }
    }
    return 0;
}