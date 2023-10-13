/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
/*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans)
    {
        if (!root) return NULL;

        TreeNode *l=lowestCommonAncestor(root->left, p, q, ans);
        TreeNode *r=lowestCommonAncestor(root->right, p ,q, ans);

        if ( (l==p && r==q) || (l==q && r==p) || (root==p && (l==q || r==q)) || (root==q && (l==p || r==p)) )
        {
            ans=root;
            return ans;
        }
        if (l==p || l==q) return l;
        if (r==p || r==q) return r;
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode *ans=NULL;
        lowestCommonAncestor(root, p, q, ans);
        return ans;
    }
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root==NULL || root==p || root==q) return root;

        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root]=NULL;

        stack<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        while (parent.count(p)==0 || parent.count(q)==0)
        {
            TreeNode *node = pendingNodes.top();
            pendingNodes.pop();

            if (node->left)
            {
                parent[node->left]=node;
                pendingNodes.push(node->left);
            }
            if (node->right)
            {
                parent[node->right]=node;
                pendingNodes.push(node->right);
            }
        }

        unordered_set<TreeNode*> parentsOfP;
        while (p)
        {
            parentsOfP.insert(p);
            p=parent[p];
        }
        while (q && parentsOfP.find(q)==parentsOfP.end())
            q=parent[q];
        return q;
    }
};