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
    int findBottomLeftValue(TreeNode* root)
    {
        int ans;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            TreeNode* node=pendingNodes.front();
            ans=node->val;
            while (sz--)
            {
                node=pendingNodes.front();
                pendingNodes.pop();
                if (node->left) pendingNodes.push(node->left);
                if (node->right) pendingNodes.push(node->right);
            }
        }
        return ans;
    }
};