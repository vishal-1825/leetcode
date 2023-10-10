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
/*
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
*/
    TreeNode* buildTreeHelper(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int, int>& inInd)
    {
        if (ps>pe || is>ie) return NULL;

        int inRind=inInd[preorder[ps]];
        int numLeft=inRind-is;

        TreeNode *root = new TreeNode(preorder[ps]);
        root->left=buildTreeHelper(preorder, ps+1, ps+numLeft, inorder, is, inRind-1, inInd);
        root->right=buildTreeHelper(preorder, ps+numLeft+1, pe, inorder, inRind+1, ie, inInd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        map<int, int> inInd;
        int n=inorder.size();

        for (int i=0; i<n; i++)
            inInd[inorder[i]]=i;
        return buildTreeHelper(preorder, 0, n-1, inorder, 0, n-1, inInd);
    }
};