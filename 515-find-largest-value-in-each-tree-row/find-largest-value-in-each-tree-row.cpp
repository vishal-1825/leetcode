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
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> ans;
        queue<TreeNode*> pendingNodes;
        if (root) pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            int maxval=INT_MIN;
            while (sz--)
            {
                TreeNode *node = pendingNodes.front();
                pendingNodes.pop();
                if (node->val>maxval)
                    maxval=node->val;
                if (node->left) pendingNodes.push(node->left);
                if (node->right) pendingNodes.push(node->right);
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};