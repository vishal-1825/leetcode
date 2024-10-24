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
    int equiv(TreeNode *root1, TreeNode *root2)
    {
        int l1=-1, r1=-1, l2=-1, r2=-1;
        if (root1->left) l1=root1->left->val;
        if (root1->right) r1=root1->right->val;
        if (root2->left) l2=root2->left->val;
        if (root2->right) r2=root2->right->val;

        if (l1==l2 && r1==r2) return 0;
        else if (l1==r2 && r1==l2) return 1;
        else return -1;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2)
    {
        if (root1==NULL && root2==NULL) return true;
        if (root1==NULL || root2==NULL) return false;
        if (root1->val!=root2->val) return false;

        if (equiv(root1, root2)==0)
            return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right));
        else if (equiv(root1, root2)==1)
            return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
        else return false;
    }
};