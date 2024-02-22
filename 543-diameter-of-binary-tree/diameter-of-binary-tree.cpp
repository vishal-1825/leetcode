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
    int height(TreeNode* root)
    {
        if (!root) return 0;
        return 1+max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTreeHelper(TreeNode* root)
    {
        if (!root) return 0;

        int lh=height(root->left);
        int rh=height(root->right);

        int ld=diameterOfBinaryTreeHelper(root->left);
        int rd=diameterOfBinaryTreeHelper(root->right); 
        return max(max(ld, rd), 1+lh+rh);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        return diameterOfBinaryTreeHelper(root)-1;
    }
};