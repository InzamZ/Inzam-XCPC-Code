#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool chmin(int &a, int b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
const int INF = 0x3fffffff;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        g[A].push_back(B);
        g[B].push_back(A);
    }
    int K;
    cin >> K;
    vector<int> C(K);
    for (int &c : C)
    {
        cin >> c;
        c--;
    }

    auto BFS = [&](int s) {
        vector cost(N, INF);
        cost[s] = 0;
        queue<int> q;
        q.push(s);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (int y : g[x])
                if (chmin(cost[y], cost[x] + 1))
                    q.push(y);
        }
        for (int i = 0; i < K; i++)
            cost[i] = cost[C[i]];
        cost.resize(K);
        return cost;
    };

    vector<vector<int>> cost(K);
    for (int i = 0; i < K; i++)
        cost[i] = BFS(C[i]);

    vector dp(1 << K, vector(K, INF));
    for (int i = 0; i < K; i++)
        dp[1 << i][i] = 1;
    for (int bit = 1; bit < 1 << K; bit++)
        for (int i = 0; i < K; i++)
            if (bit & 1 << i)
            {
                const int bit2 = bit ^ 1 << i;
                for (int j = 0; j < K; j++)
                    if (bit2 & 1 << j)
                        chmin(dp[bit][i], dp[bit2][j] + cost[i][j]);
            }

    int ans = *min_element(dp.back().begin(), dp.back().end());
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}