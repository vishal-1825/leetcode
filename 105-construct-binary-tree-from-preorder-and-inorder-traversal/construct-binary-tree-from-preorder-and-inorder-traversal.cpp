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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder)
    {
        int n=inorder.size();
        if (n==0) return NULL;

        TreeNode *root = new TreeNode(preorder[0]);
        int i;
        for (i=0; i<n; i++)
        {
            if (root->val==inorder[i])
                break;
        }

        vector<int> leftPre(preorder.begin()+1, preorder.begin()+1+i);
        vector<int> rightPre(preorder.begin()+1+i, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin()+i);
        vector<int> rightIn(inorder.begin()+i+1, inorder.end());
        
        root->left=buildTree(leftPre, leftIn);
        root->right=buildTree(rightPre, rightIn);
        return root;
    }
};