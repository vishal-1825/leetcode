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
    void getSum(TreeNode* root, int& sum, int s)
    {
        if (!root->left && !root->right)
        {
            sum+=s*10+root->val;
            return;
        }

        if (root->left) getSum(root->left, sum, s*10+root->val);
        if (root->right) getSum(root->right, sum, s*10+root->val);
    }
    int sumNumbers(TreeNode* root)
    {
        if (!root) return 0;

        int sum=0;
        getSum(root, sum, 0);
        return sum;
    }
};