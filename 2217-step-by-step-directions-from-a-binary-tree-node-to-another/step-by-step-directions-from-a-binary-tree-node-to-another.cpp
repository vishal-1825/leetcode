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
    string ans1="", ans2="";
    void getPath(TreeNode *LCA, int& sv, int& dv, string& path)
    {
        if (!LCA) return;
        
        if (LCA->val==sv) ans1=path;
        if (LCA->val==dv) ans2=path;
        path+='L';
        getPath(LCA->left, sv, dv, path);
        path.pop_back();
        path+='R';
        getPath(LCA->right, sv,dv, path);
        path.pop_back();
    }

    TreeNode* getLCA(TreeNode* root, int& sv, int& dv)
    {
        if (!root || root->val==sv || root->val==dv) return root;

        TreeNode *leftAns=getLCA(root->left, sv, dv);
        TreeNode *rightAns=getLCA(root->right, sv, dv);

        if (!leftAns) return rightAns;
        if (!rightAns) return leftAns;
        return root;
    }

    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        if (!root) return "";

        TreeNode *LCA = getLCA(root, startValue, destValue);
        if (LCA) cout << LCA->val << endl;
        string path="";
        getPath(LCA, startValue, destValue, path);
        string ans3="";
        for (int i=0; i<ans1.length(); i++)
            ans3+='U';
        return ans3+ans2;
    }
};