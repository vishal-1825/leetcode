/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* insert(vector<int>& nums, int l, int r)
    {
        if (l>r) return NULL;

        int m=(l+r)/2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left=insert(nums, l, m-1);
        root->right=insert(nums, m+1, r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (!head) return NULL;

        vector<int> nums;
        ListNode *temp=head;
        while (temp!=NULL)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        TreeNode *root = insert(nums, 0, nums.size()-1);
        return root;
    }
};