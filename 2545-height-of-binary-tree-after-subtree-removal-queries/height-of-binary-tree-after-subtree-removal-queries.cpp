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
    int heightAfterRemoval[100001];
    int maxHeight=0;
    void leftRightTraversal(TreeNode *root, int height)
    {
        if (root==NULL) return;

        heightAfterRemoval[root->val]=maxHeight;
        maxHeight=max(maxHeight, height);
        leftRightTraversal(root->left, height+1);
        leftRightTraversal(root->right, height+1);
    }
    void rightLeftTraversal(TreeNode *root, int height)
    {
        if (root==NULL) return;

        heightAfterRemoval[root->val]=max(heightAfterRemoval[root->val], maxHeight);
        maxHeight=max(maxHeight, height);
        rightLeftTraversal(root->right, height+1);
        rightLeftTraversal(root->left, height+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        leftRightTraversal(root, 0);
        maxHeight=0;
        rightLeftTraversal(root, 0);
        vector<int> ans;
        for (int q: queries)
            ans.push_back(heightAfterRemoval[q]);
        return ans;
    }
};