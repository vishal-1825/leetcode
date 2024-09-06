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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        if (!head) return head;

        unordered_set<int> array;
        for (int n: nums)
            array.insert(n);
        
        ListNode *dummy = new ListNode(0), *prev = dummy, *cur = head;
        dummy->next=head;
        while (cur)
        {
            while (cur && array.find(cur->val)!=array.end())
                cur=cur->next;
            prev->next=cur;
            prev=prev->next;
            if (cur) cur=cur->next;
        }
        head=dummy->next;
        delete dummy;
        return head;
    }
};