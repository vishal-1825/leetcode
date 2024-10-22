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
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        vector<long long> sums;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            long long sum=0;
            while (sz--)
            {
                TreeNode *node = pendingNodes.front();
                pendingNodes.pop();
                sum+=(long long)node->val;
                if (node->left) pendingNodes.push(node->left);
                if (node->right) pendingNodes.push(node->right);
            }
            sums.push_back(sum);
        }
        if (sums.size()<k) return -1;
        sort(sums.begin(), sums.end(), greater<long long>());
        return sums[k-1];
    }
};