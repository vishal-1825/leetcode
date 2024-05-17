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
    TreeNode* removeLeaf(TreeNode* root, int target)
    {
        if (!root) return root;

        root->left=removeLeaf(root->left, target);
        root->right=removeLeaf(root->right, target);

        TreeNode *leftChild=NULL, *rightChild=NULL;
        if (root->left) leftChild=root->left;
        if (root->right) rightChild=root->right;
        if (leftChild!=NULL && leftChild->val==target && leftChild->left==NULL && leftChild->right==NULL) root->left=NULL;
        if (rightChild!=NULL && rightChild->val==target && rightChild->left==NULL && rightChild->right==NULL) root->right=NULL;
        return root;
    } 
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        TreeNode* head=removeLeaf(root, target);
        if (head!=NULL && head->val==target && head->left==NULL && head->right==NULL) return NULL;
        return head;
    }
};