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
    void getLeftMax(TreeNode* root, int &l)
    {
        if (!root) return;

        l=max(l, root->val);
        getLeftMax(root->left, l);
        getLeftMax(root->right, l);
    }
    void getRightMin(TreeNode* root, int &r)
    {
        if (!root) return;

        r=min(r, root->val);
        getRightMin(root->left, r);
        getRightMin(root->right, r);
    }
    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;

        int l=INT_MIN, r=INT_MAX;
        if (root->left)
        {
            getLeftMax(root->left, l);
            if (l>=root->val) return false;
        }
        if (root->right)
        {
            getRightMin(root->right, r);
            if (r<=root->val) return false;
        }
        
        if (!isValidBST(root->left)) return false;
        return isValidBST(root->right);
    }
};