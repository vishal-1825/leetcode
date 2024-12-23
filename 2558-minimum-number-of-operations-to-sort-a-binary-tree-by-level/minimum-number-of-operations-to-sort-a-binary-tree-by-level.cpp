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
    int operations(vector<int> values)
    {
        vector<int> sortedValues(values.begin(), values.end());
        sort(sortedValues.begin(), sortedValues.end());

        unordered_map<int, int> index;
        for (int i=0; i<values.size(); i++)
            index[values[i]]=i;
        
        int i=0, ops=0;
        for (int i=0; i<values.size(); i++)
        {
            if (sortedValues[i]!=values[i])
            {
                int swapIndex=index[sortedValues[i]];
                index[values[i]]=swapIndex;
                index[values[swapIndex]]=i;
                swap(values[i], values[swapIndex]);
                ops++;
            }
        }
        return ops;
    }
    int minimumOperations(TreeNode* root)
    {
        if (!root) return 0;

        int ans=0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            vector<int> values;
            while (sz--)
            {
                TreeNode *node = pendingNodes.front();
                pendingNodes.pop();
                values.push_back(node->val);

                if (node->left) pendingNodes.push(node->left);
                if (node->right) pendingNodes.push(node->right);
            }
            ans+=operations(values);
        }
        return ans;
    }
};