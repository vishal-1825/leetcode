/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans)
    {
        if (!root) return NULL;

        TreeNode *l=lowestCommonAncestor(root->left, p, q, ans);
        TreeNode *r=lowestCommonAncestor(root->right, p ,q, ans);

        if ( (l==p && r==q) || (l==q && r==p) || (root==p && (l==q || r==q)) || (root==q && (l==p || r==p)) )
        {
            ans=root;
            return ans;
        }
        if (l==p || l==q) return l;
        if (r==p || r==q) return r;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode *ans=NULL;
        lowestCommonAncestor(root, p, q, ans);
        return ans;
    }
};