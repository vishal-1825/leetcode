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
    void getNodes(TreeNode* root, vector<int>& postfixSum)
    {
        if (!root) return;

        getNodes(root->left, postfixSum);
        postfixSum.push_back(root->val);
        getNodes(root->right, postfixSum);
    }
    void replaceValues(TreeNode* root, vector<int>& postfixSum, int& i)
    {
        if (!root) return;

        replaceValues(root->left, postfixSum, i);
        root->val=postfixSum[i++];
        replaceValues(root->right, postfixSum, i);
    }
    TreeNode* bstToGst(TreeNode* root)
    {
        vector<int> postfixSum;
        getNodes(root, postfixSum);
        for (int i=postfixSum.size()-2; i>=0; i--)
            postfixSum[i]+=postfixSum[i+1];
        int i=0;
        replaceValues(root, postfixSum, i);
        return root;
    }
};