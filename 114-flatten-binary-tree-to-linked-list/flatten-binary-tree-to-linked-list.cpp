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
    TreeNode* flattenHelper(TreeNode* root)
    {
        if (!root) return root;

        TreeNode *l=flattenHelper(root->left);
        TreeNode *r=flattenHelper(root->right);

        root->left=NULL;
        root->right=NULL;
        if (l) root->right=l;
        if (!r) return root;

        TreeNode *temp=root;
        while (temp && temp->right)
            temp=temp->right;
        if (temp) temp->right=r;
        
        return root;
    }
    void flatten(TreeNode* root)
    {
        root=flattenHelper(root);
    }
};