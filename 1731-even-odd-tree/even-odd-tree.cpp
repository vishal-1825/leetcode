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
    bool isEvenOddTree(TreeNode* root)
    {
        int level=0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            int prev = ((level%2==0) ? INT_MIN : INT_MAX);
            while (sz--)
            {
                TreeNode *node = pendingNodes.front();
                pendingNodes.pop();
                int value = node->val;
                if (level%2==0 && (value%2==0 || value<=prev)) return false;
                if (level%2==1 && (value%2==1 || value>=prev)) return false;
                prev=value;

                if (node->left) pendingNodes.push(node->left);
                if (node->right) pendingNodes.push(node->right);
            }
            level++;
        }
        return true;
    }
};