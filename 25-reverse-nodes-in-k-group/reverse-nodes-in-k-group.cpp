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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head || !head->next || k<=1) return head;

        ListNode *dummy = new ListNode(-1);
        ListNode *ptr=dummy, *left=head, *right=head;
        while (right)
        {
            int i;
            for (i=1; right && i<k; i++)
                right=right->next;
            
            if (right)
            {
                ListNode *prev=NULL, *cur=left, *nxt=left, *r=right;
                right=right->next;
                while (cur && cur!=right)
                {
                    nxt=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=nxt;
                }
                ptr->next=r;
                ptr=left;
                left=right;
            }
            else ptr->next=left;
        }
        return dummy->next;
    }
};