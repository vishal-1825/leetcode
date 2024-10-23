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
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        vector<int> levelSum;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sum=0, sz=pendingNodes.size();
            while (sz--)
            {
                TreeNode *node = pendingNodes.front();
                pendingNodes.pop();
                sum+=node->val;
                if (node->left) pendingNodes.push(node->left);
                if (node->right) pendingNodes.push(node->right);
            }
            levelSum.push_back(sum);
        }
        int level=0;
        root->val=0;
        pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            while (sz--)
            {
                TreeNode *node = pendingNodes.front();
                pendingNodes.pop(); 
                int childSum=0;
                if (node->left) childSum+=node->left->val;
                if (node->right) childSum+=node->right->val;
                if (node->left)
                {
                    node->left->val=levelSum[level+1]-childSum;
                    pendingNodes.push(node->left);
                }
                if (node->right)
                {
                    node->right->val=levelSum[level+1]-childSum;
                    pendingNodes.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};