//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pii = pair<int,int>;
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        auto cmp = [&](int x,int y)
        {
            int res1 = time[x][0] + time[x][2];
            int res2 = time[y][0] + time[y][2];
            return res1 != res2 ? res1 < res2 : x < y;
        };
        priority_queue<int, vector<int>, decltype(cmp)> L(cmp),R(cmp);
        priority_queue<pii, vector<pii>, greater<pii> > wl,wr;
        int rest = n,cur = 0;
        for (int i = 0; i < k; ++i) L.push(i);
        while (rest > 0 || !wr.empty() || !R.empty())
        {
            while (wr.size() && wr.top().first <= cur) {
                R.push(wr.top().second);
                wr.pop();
            }
            while (wl.size() && wl.top().first <= cur) {
                L.push(wl.top().second);
                wl.pop();
            }
            if (!R.empty())
            {
                cur += time[R.top()][2];
                wl.push({cur+time[R.top()][3],R.top()});
                R.pop();
            }
            else if (rest > 0 && !L.empty())
            {
                int id = L.top();
                cur += time[id][0];
                wr.push({cur + time[id][1],id});
                --rest;
                L.pop();
            }
            else 
            {
                int t = 1e9;
                if (!wl.empty()) t = min(t,wl.top().first);
                if (!wr.empty()) t = min(t,wr.top().first);
                if (t != 1e9) cur = max(cur,t);
            }
        }
        return cur;
    }
};



int main() {
    Solution sol;
    return 0;
}