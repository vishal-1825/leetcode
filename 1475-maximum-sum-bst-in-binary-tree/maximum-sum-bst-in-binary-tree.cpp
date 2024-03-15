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
    // isBST, min, max, sum
    vector<int> maxSumBSThelp(TreeNode* root, int &ans)
    {
        if (!root) return {1, INT_MAX, INT_MIN, 0};

        vector<int> leftAns=maxSumBSThelp(root->left, ans);
        vector<int> rightAns=maxSumBSThelp(root->right, ans);

        int isBST=0;
        if (leftAns[0] && rightAns[0] && leftAns[2]<root->val && rightAns[1]>root->val)
        {
            isBST=1;
            ans=max(ans, root->val+leftAns[3]+rightAns[3]);
        }
        int minval=min({root->val, leftAns[1], rightAns[1]});
        int maxval=max({root->val, leftAns[2], rightAns[2]});
        int sum=root->val+leftAns[3]+rightAns[3];
        return {isBST, minval, maxval, sum};
    }
    int maxSumBST(TreeNode* root)
    {
        int ans=0;
        maxSumBSThelp(root, ans);
        return ans;
    }
};