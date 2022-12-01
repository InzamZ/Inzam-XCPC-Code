//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define endl '\n'
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  public:
    void dfs(TreeNode *rt, TreeNode *f, int type) {
        TreeNode *cur = new TreeNode(rt->val);
        if (type == 1) {
            f->left = new TreeNode(-1, cur, nullptr);
        }
        if (type == 2)
        {
            f->right = new TreeNode(-1, nullptr, cur);
        }
        if (rt->left)
            dfs(rt->left, cur, 1);
        if (rt->right)
            dfs(rt->right, cur, 2);
    }
    TreeNode *expandBinaryTree(TreeNode *root) {
        TreeNode *newrt = new TreeNode(root->val);
        if (root->left)
            dfs(root->left, newrt, 1);
        if (root->right)
            dfs(root->right, newrt, 2);
        return newrt;
    }
};