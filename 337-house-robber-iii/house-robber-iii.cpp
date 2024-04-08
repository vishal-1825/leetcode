/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode *root, TreeNode *prev, unordered_map<TreeNode*, unordered_map<TreeNode*, int>>& dp)
    {
        if (!root) return 0;

        // if (dp[root][prev]!=0) return dp[root][prev];
        if (dp.find(root)!=dp.end() && dp[root].find(prev)!=dp[root].end()) return dp[root][prev];

        int inc=INT_MIN, exc;
        if (prev==NULL || (prev->left!=root && prev->right!=root)) inc=root->val+rob(root->left, root, dp)+rob(root->right, root, dp);
        exc=rob(root->left, prev, dp)+rob(root->right, prev, dp);
        return dp[root][prev]=max(inc, exc);
    }
    int rob(TreeNode* root)
    {
        unordered_map<TreeNode*, unordered_map<TreeNode*, int>> dp;
        return rob(root, NULL, dp);    
    }
    
};