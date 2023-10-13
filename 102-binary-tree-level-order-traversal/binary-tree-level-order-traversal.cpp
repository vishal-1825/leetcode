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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        while (!pendingNodes.empty())
        {
            vector<int> v;
            while (!pendingNodes.empty() && pendingNodes.front()!=NULL)
            {
                TreeNode *node=pendingNodes.front();
                pendingNodes.pop();
                v.push_back(node->val);
                if (node->left) pendingNodes.push(node->left);
                if (node->right) pendingNodes.push(node->right);
            }
            if (pendingNodes.size()==1) pendingNodes.pop();
            else if (!pendingNodes.empty() && pendingNodes.front()==NULL)
            {
                pendingNodes.pop();
                pendingNodes.push(NULL);
            }
            if (!v.empty()) ans.push_back(v);
        }
        return ans;
    }
};