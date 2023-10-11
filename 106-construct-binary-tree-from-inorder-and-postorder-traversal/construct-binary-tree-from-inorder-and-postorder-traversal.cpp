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
    TreeNode* buildTree(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& inInd)
    {
        if (is>ie || ps>pe) return NULL;

        TreeNode *root = new TreeNode(postorder[pe]);
        int inRind=inInd[root->val], numLeft=inRind-is;
        root->left=buildTree(inorder, is, is+numLeft-1, postorder, ps, ps+numLeft-1, inInd);
        root->right=buildTree(inorder, inRind+1, ie, postorder, ps+numLeft, pe-1, inInd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n=inorder.size(), i;
        map<int, int> inInd;
        for (i=0; i<n; i++)
            inInd[inorder[i]]=i;
        
        return buildTree(inorder, 0, n-1, postorder, 0, n-1, inInd);
    }
};