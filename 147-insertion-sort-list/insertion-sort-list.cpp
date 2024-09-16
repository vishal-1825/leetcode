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
    ListNode* insertionSortList(ListNode* head)
    {
        if (!head || !head->next) return head;

        ListNode *dummy = new ListNode();
        ListNode *cur=head;
        while (cur!=NULL)
        {
            ListNode *ptr=dummy;
            while (ptr->next!=NULL && cur->val>ptr->next->val)
                ptr=ptr->next;
            ListNode *nxt = cur->next;
            cur->next=ptr->next;
            ptr->next=cur;
            cur=nxt;
        }
        head=dummy->next;
        delete dummy;
        return head;
    }
};