
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0, sum = 0;
        return dfs(root, sum, ans);
    }

    int dfs(TreeNode *root, int &sum, int &cnt)
    {
        int ans = 0, Lsum = sum, Lcnt = cnt;
        if (!root)
            return 0;
        ans += dfs(root->left, sum, cnt);
        ans += dfs(root->right, sum, cnt);
        ++cnt;
        sum += root->val;
        if ((cnt - Lcnt) && (sum - Lsum) / (cnt - Lcnt) == root->val)
            ++ans;
        return ans;
    }
};