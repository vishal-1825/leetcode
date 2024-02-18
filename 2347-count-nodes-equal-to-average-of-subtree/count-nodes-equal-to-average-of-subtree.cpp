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
    // sum, count
    pair<int, int> getCount(TreeNode* root, int& counts)
    {
        if (!root) return {0, 0};

        pair<int, int> l = getCount(root->left, counts);
        pair<int, int> r = getCount(root->right, counts);

        int sum = l.first + r.first + root->val;
        int count = l.second + r.second + 1;
        if ((sum/count)==root->val) counts++;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root)
    {
        int counts=0;
        getCount(root, counts);
        return counts;
    }
};