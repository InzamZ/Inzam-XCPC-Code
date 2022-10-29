//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, B, p[6], tmp = 0, ans = 0;
vector<string>tmps,anss;

struct peo {
    string name;
    int w;
    peo(string _name, int _w): name(_name), w(_w) {}
    bool operator < (const peo &rhs) const
    {
        return w == rhs.w ? name > rhs.name : w < rhs.w;
    }
};
vector<peo>pp[5];

int dfs(int id)
{
    if (tmp > B) return 0;
    if (id == 5)
    {
        int it = upper_bound(pp[0].begin(),pp[0].end(),peo{"", B - tmp}) - pp[0].begin();
        if (it == 0) return 0;
        --it;
        tmp += pp[0][it].w;
        tmps[0] = (pp[0][it].name);
        if (tmp > ans) 
        {
            ans = tmp;
            anss = tmps;
        }
        else if (tmp == ans)
        {
            for(int i = 0; i < 4; ++i)
            {
                if (anss[i] == tmps[i]) continue;
                else if (anss[i] < tmps[i]) break;
                else 
                {
                    anss = tmps;
                    break;
                }
            }
        }
        tmp -= pp[0][it].w;
        return 0;
    }
    f(i,0,p[id] - 1)
    {
        tmps.push_back(pp[id][i].name);
        tmp += pp[id][i].w;
        dfs(id+1);
        tmps.pop_back();
        tmp -= pp[id][i].w;
    }
    return 0;
}

int solve() {
    ans = 0;
    cin >> B;
    f(i,0,4)
    {
        cin >> p[i];
        f(j,1,p[i])
        {
            string a;
            int b;
            cin >> a >> b;
            pp[i].push_back(peo(a,b));
        }
    }
    tmps.push_back("");
    sort(pp[0].begin(),pp[0].end());
    dfs(1);
    for (auto x: anss)
        cout << x << '\n';
    return 0;
}

signed main() {
    FIO;
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}