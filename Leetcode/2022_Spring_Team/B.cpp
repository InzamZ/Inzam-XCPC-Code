//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        cout << ans << '\n';
    }
    return 0;
}

class Solution
{
public:
    vector<int> partx[10005];
    vector<int> party[10005];
    bool visited[105][105];
    int part[105][105];
    vector<string> mat;
    int conveyorBelt(vector<string> &matrix, vector<int> &start, vector<int> &end)
    {
        int partnum = 0;
        mat = vector<string>(matrix);
        for (int i = 0; i < matrix.size(); i++) {
            for (int k = 0; k < matrix[i].length(); k++) {
                visited[i][k] = false;
                part[i][k] = 0;
            }
        }
        partnum++;
        nxt(start[0], start[1], partnum);
        int cnt = 0;
        int lastcnt = 0;
        while (part[start[0]][start[1]] != part[end[0]][end[1]]) {
            cnt++;
            int l = partx[part[start[0]][start[1]]].size();
            for (int i = lastcnt; i < l; i++) {
                int x = partx[part[start[0]][start[1]]][i], y = party[part[start[0]][start[1]]][i];
                if (x != 0) {
                    if (part[x][y] != part[x - 1][y]) {
                        nxt(x - 1, y, ++partnum);
                        chan(part[x - 1][y], part[x][y]);
                    }
                }
                if (x != matrix.size() - 1) {
                    if (part[x][y] != part[x + 1][y]) {
                        nxt(x + 1, y, ++partnum);
                        chan(part[x + 1][y], part[x][y]);
                    }
                }
                if (y != 0) {
                    if (part[x][y] != part[x][y - 1]) {
                        nxt(x, y - 1, ++partnum);
                        chan(part[x][y - 1], part[x][y]);
                    }
                }
                if (y != matrix[0].size() - 1) {
                    if (part[x][y] != part[x][y + 1]) {
                        nxt(x, y + 1, ++partnum);
                        chan(part[x][y + 1], part[x][y]);
                    }
                }
            }
            lastcnt = l;
        }
        cnt = min(cnt, abs(start[0] - end[0]) + abs(start[1] - end[1]));
        return cnt;
    }
    void chan(int parta, int partb)
    {
        for (int i = 0; i < partx[parta].size(); i++) {
            part[partx[parta][i]][party[parta][i]] = partb;
            partx[partb].push_back(partx[parta][i]);
            party[partb].push_back(party[parta][i]);
        }
    }
    void nxt(int x, int y, int ppart)
    {
        if (visited[x][y])
            return ;
        part[x][y] = ppart;
        partx[ppart].push_back(x);
        party[ppart].push_back(y);
        visited[x][y] = true;
        if (mat[x][y] == '^') {
            if (x == 0)
                return;
            nxt(x - 1, y, ppart);
        }
        else if (mat[x][y] == 'v') {
            if (x == mat.size() - 1)
                return ;
            nxt(x + 1, y, ppart);
        }
        else if (mat[x][y] == '<') {
            if (y == 0)
                return;
            nxt(x, y - 1, ppart);
        }
        else {
            if (y == mat[0].length() - 1)
                return ;
            nxt(x, y + 1, ppart);
        }
    }
};