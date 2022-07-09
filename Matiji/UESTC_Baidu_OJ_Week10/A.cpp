//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, y, x, ans = 0, vis[maxn], b[maxn];
int imap[10][10];

void printit() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j)
            cout << imap[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int dfs(int i, int j) {
    if (i !=1 && j == 1) {
        //每一行开始检查上一行是否合法
        if (imap[i - 1][4] + imap[i - 1][1] + imap[i - 1][2] + imap[i - 1][3] == 34)
            return 0;
        //最后一行开始需要检查第四列是否合法
        if (i == 5 && imap[1][4] + imap[2][4] + imap[3][4] + imap[4][4] == 34)
            return 0;
    }
    else 
    {
        //第四行每次填数检查列数是否合法
        if (i == 4 && imap[1][j - 1] + imap[2][j - 1] + imap[3][j - 1] + imap[4][j - 1] != 34)
            return 0;
    }
    //每个可以判断的节点都检查一下，不合法直接return
    if (i == 2 && j == 3 && imap[1][1] + imap[1][2] + imap[2][1] + imap[2][2] != 34) return 0;
    if (i == 4 && j == 2 && imap[1][3] + imap[1][4] + imap[2][3] + imap[2][4] != 34) return 0;
    if (i == 3 && j == 4 && imap[3][1] + imap[3][2] + imap[4][1] + imap[4][2] != 34) return 0;
    if (i == 5 && j == 1 && imap[3][3] + imap[3][4] + imap[4][3] + imap[4][4] != 34) return 0;
    if (i == 2 && j == 3 && imap[1][1] + imap[2][2] + imap[3][3] + imap[4][4] != 34) return 0;
    if (i == 3 && j == 1 && imap[4][1] + imap[3][2] + imap[2][3] + imap[1][4] != 34) return 0;
    if (i == 3 && j == 4 && imap[2][2] + imap[3][2] + imap[2][3] + imap[3][3] != 34) return 0;
    if (i == 5 && j == 1)
    {
        //合法输出
        printit();
        return 0;
    }
    //跳过预先确定的
    if (i == x && j == y)
        dfs(i + (j == 4), j % 4 + 1);
    else {
        //填数，一个一个试，之前没有填过的都试一次
        for (int k = 1; k <= 16; ++k) {
            if (vis[k])
                continue;
            imap[i][j] = k;
            vis[k] = 0;
            dfs(i + (j == 4), j % 4 + 1);
            vis[k] = 1;
        }
    }
    return 0;
}

int solve() {
    ans = 0;
    cin >> n >> x >> y;
    //标记每个数是否填入
    vis[n] = 1;
    imap[x][y] = n;
    //从第一行第一列开始填写
    dfs(1, 1);
    return 0;
}

signed main() {
    FIO;
    solve();
    return 0;
}