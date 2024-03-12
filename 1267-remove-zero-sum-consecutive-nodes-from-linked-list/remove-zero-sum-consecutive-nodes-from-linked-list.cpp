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
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        if (!head) return head;
        
        int sum=0;
        ListNode *temp=head, *node=NULL;
        while (temp!=NULL)
        {
            sum+=temp->val;
            if (sum==0) node=temp;
            temp=temp->next;
        }
        if (node!=NULL) head=node->next;
        if (!head) return head;
        
        ListNode* remaining = removeZeroSumSublists(head->next);
        head->next=remaining;
        return head;
    }
};