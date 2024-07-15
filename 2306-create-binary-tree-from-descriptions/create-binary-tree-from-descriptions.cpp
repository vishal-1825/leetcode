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
    TreeNode* buildTree(int rootval, unordered_map<int, int>& leftChild, unordered_map<int, int>& rightChild)
    {
        TreeNode *root = new TreeNode(rootval);
        if (leftChild.find(rootval)!=leftChild.end()) root->left=buildTree(leftChild[rootval], leftChild, rightChild);
        if (rightChild.find(rootval)!=rightChild.end()) root->right=buildTree(rightChild[rootval], leftChild, rightChild);
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        unordered_map<int, int> parent, leftChild, rightChild;
        for (auto d: descriptions)
        {
            parent[d[1]]=d[0];
            if (d[2]==1) leftChild[d[0]]=d[1];
            else rightChild[d[0]]=d[1];
        }

        int rootval=descriptions[0][0];
        while (parent.find(rootval)!=parent.end())
            rootval=parent[rootval];

        return buildTree(rootval, leftChild, rightChild);
    }
};