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
    void smallestFromLeaf(TreeNode* root, string str, string& ans)
    {
        if (!root) return;
        if (!root->left && !root->right)
        {
            if (ans=="" || char('a'+root->val)+str < ans)
                ans=char('a'+root->val)+str;
            return;
        }

        smallestFromLeaf(root->left, char('a'+root->val)+str, ans);
        smallestFromLeaf(root->right, char('a'+root->val)+str, ans);
    }
    string smallestFromLeaf(TreeNode* root)
    {
        string ans="";
        smallestFromLeaf(root, "", ans);
        return ans;    
    }
};