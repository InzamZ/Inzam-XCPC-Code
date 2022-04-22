#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class ChthollyTree
{
public:
    struct Node {
        int l, r;
        mutable ll value;//
        Node(int a, int b, long long c): l(a), r(b), value(c) {}
        Node(int a): l(a), r(0), value(0) {}
        bool operator < (const Node &o) const
        {
            return l < o.l;
        }
    };

    set<Node>s;

    set<Node>::iterator split(int pos)
    {
        set<Node>::iterator it = s.lower_bound(Node(pos));
        if (it->l == pos && it != s.end())
            return it;//
        --it;
        if (pos > it->r)
            return s.end();//
        int L = it->l, R = it->r;
        ll V = it->value;
        s.erase(it);
        s.insert(Node(L, pos - 1, V));
        return s.insert(Node(pos, R, V)).first;
    }

    void assign(int l, int r, int v)
    {
        split(l);
        set<Node>::iterator R = split(r + 1);
        set<Node>::iterator L = split(l);
        s.erase(L, R);
        s.insert(Node(l, r, v));
    }

    ll sum()
    {
        int ans = 0;
        for (auto it : s) {
            if (it.value)
                ans += ( (ll)( it.r - it.l + 1 ));
        }
        return ans;
    }
};

class Solution
{
public:
    int getNumber(TreeNode *root, vector<vector<int>> &ops)
    {
        vector<int>s;
        queue<TreeNode *>q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *nd = q.front(); q.pop();
            s.push_back(nd->val);
            if (nd->left)
                q.push(nd->left);
            if (nd->right)
                q.push(nd->right);
        }
        sort(s.begin(), s.end());
        ChthollyTree CTree;
        CTree.s.insert(ChthollyTree::Node(0, s.size(), 0));
        for (int i = 0; i < ops.size(); ++i) {
            int l = lower_bound(s.begin(), s.end(), ops[i][1]) - s.begin();
            int r = lower_bound(s.begin(), s.end(), ops[i][2]) - s.begin();
            CTree.assign(l, r, ops[i][0]);
        }
        return CTree.sum();
    }
};