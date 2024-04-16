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
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (!root) return root;
        if (depth==1)
        {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left=root;
            root=newRoot;
            return root;
        }

        int d=0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            d++;
            while (sz--)
            {
                TreeNode *node = pendingNodes.front();
                pendingNodes.pop();
                
                if (d==depth-1)
                {
                    TreeNode *newleft = new TreeNode(val);
                    TreeNode *oldleft = node->left;
                    node->left=newleft;
                    newleft->left=oldleft;
                }
                else if (node->left) pendingNodes.push(node->left);
                
                if (d==depth-1)
                {
                    TreeNode *newright = new TreeNode(val);
                    TreeNode *oldright = node->right;
                    node->right=newright;
                    newright->right=oldright;
                }
                else if (node->right) pendingNodes.push(node->right);
            }
        }

        return root;
    }
};