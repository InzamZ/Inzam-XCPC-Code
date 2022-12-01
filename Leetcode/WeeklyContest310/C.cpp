//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
  public:
    static bool cmp(const vector<int>& a,const vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int minGroups(vector<vector<int>> &intervals) {
        priority_queue<int, vector<int>, greater<int> >q;
        q.push(0);
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); ++i) {
            if (q.top() < intervals[i][0]) {
                q.pop();
                q.push(intervals[i][1]);
            }
            else
                q.push(intervals[i][1]);
        }
        return q.size();
    }
};

class FenwickTree {
  public:
    FenwickTree(int _n) : n(_n) {}
    int n = 1000005;
    vector<int> ta;
    FenwickTree() {
        ta = vector<int>(n, 0);
    }
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

class Solution {
  public:
    static bool cmp(const vector<int>& a,const vector<int>& b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
    }
    int minGroups(vector<vector<int>> &intervals) {
        int ans = 1;
        FenwickTree *t = new FenwickTree();
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); ++i) {
            int l = intervals[i][0], r = intervals[i][1];
            t->update(l, 1);
            t->update(r + 1, -1);
            ans = max(ans, t->getsum(r));
        }
        return ans;
    }
};
int main() {
    Solution ss;
    string s = "abacaba";
    return 0;
}