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
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        int level=0;
        queue<TreeNode*> pendingNodes;
        if (root) pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            if (level & 1)
            {
                stack<int> values;
                vector<TreeNode*> nodes;
                while (!pendingNodes.empty())
                {
                    values.push(pendingNodes.front()->val);
                    nodes.push_back(pendingNodes.front());
                    pendingNodes.pop();
                }
                for (auto& node: nodes)
                {
                    node->val=values.top();
                    values.pop();
                    pendingNodes.push(node);
                }
            }
            while (sz--)
            {
                TreeNode *node = pendingNodes.front();
                pendingNodes.pop();

                if (node->left) pendingNodes.push(node->left);
                if (node->right) pendingNodes.push(node->right);
            }
            level++;
        }
        return root;
    }
};