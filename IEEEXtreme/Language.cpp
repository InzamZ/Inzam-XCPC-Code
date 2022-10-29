//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 1e4 + 10;
const int maxb = 110;
int T = 1, n, m, rt, tids[maxn], b[maxn], len = 0;
int charset[maxn];
char tmp[1005];
struct Inputdata {
    string tp, ch;
    int id, l, r;
} input[10005];
struct inode {
    int l, r, ch;
    bool Leaf;
    string name;
} Tree[10005];
vector<int>v, treec;
vector<string>ans;
string s;

int dfs(int rt)
{
    if (Tree[rt].Leaf)
    {
        ans.push_back(Tree[rt].name);
        return 0;
    }
    int idx = lower_bound(treec.begin(),treec.end(),Tree[rt].ch) - treec.begin();
    if (charset[idx] == 1) 
    {
        dfs(Tree[rt].l);
    }
    else {
        dfs(Tree[rt].l);
        dfs(Tree[rt].r);
    }
    return 0;
}

int conv_utf8_int(string tmp) {
    int res = 0;
    for (auto x : tmp) {
        res |= (unsigned char)x;
        res <<= 8;
    }
    res >>= 8;
    return res;
}

int solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> input[i].tp >> input[i].id >> input[i].ch;
        if (input[i].tp == "I")
            cin >> input[i].l >> input[i].r;
        v.push_back(input[i].id);
    }
    v.push_back(-1);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= m; ++i) {
        input[i].id = lower_bound(v.begin(), v.end(), input[i].id) - v.begin();
        Tree[input[i].id].Leaf = input[i].tp == "L";
        if (Tree[input[i].id].Leaf)
            Tree[input[i].id].name = input[i].ch;
        else {
            input[i].l = lower_bound(v.begin(), v.end(), input[i].l) - v.begin();
            input[i].r = lower_bound(v.begin(), v.end(), input[i].r) - v.begin();
            Tree[input[i].id].ch = conv_utf8_int(input[i].ch);
            treec.push_back(Tree[input[i].id].ch);
            Tree[input[i].id].l = input[i].l;
            Tree[input[i].id].r = input[i].r;
            b[input[i].l] = 1;
            b[input[i].r] = 1;
        }
    }
    sort(treec.begin(), treec.end());
    treec.resize(unique(treec.begin(), treec.end()) - treec.begin());
    for (int i = 1; i < v.size(); ++i) {
        if (b[i] == 0) {
            rt = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        ans.clear();
        len = 0;
        tmp[len] = getchar();
        while ( tmp[len] == '\n')
            tmp[len] = getchar();
        while (1) {
            tmp[++len] = getchar();
            if (tmp[len] == '\n')
                break;
        }
        s = tmp;
        s.resize(len);
        string ch = "";
        memset(charset, 0, sizeof(charset));
        for (int j = 0; j < s.size();) {
            ch = "";
            int cnt = 0;
            unsigned char base = (1 << 7);
            while (s[j] & base) {
                ++cnt;
                base >>= 1;
            }
            if (cnt == 0)
                cnt = 1;
            for (int _ = 0; _ < cnt; ++_)
                ch += s[j + _];
            j+= cnt;
            cnt = conv_utf8_int(ch);
            int idx = lower_bound(treec.begin(), treec.end(), cnt) - treec.begin();
            if (treec[idx] == cnt)
                charset[idx] = 1;
        }
        dfs(rt);
        sort(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << " ";
        cout << '\n';
    }
    return 0;
}

signed main() {
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}