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
    void reorderList(ListNode* head)
    {
        if (!head || head->next==NULL || head->next->next==NULL) return;
        
        ListNode *slow=head, *fast=head;
        // find mid
        while (fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        //reverse 2nd half
        ListNode *prev=slow, *cur=slow->next, *next=slow->next;
        prev->next=NULL;
        while (cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;

            prev=cur;
            cur=next;
        }
        // prev holds last element
        // attach i with n-i
        ListNode *left=head, *right=prev;
        while (true)
        {
            if (left==right || left->next==right)
            {
                right->next=NULL;
                break;
            }
            ListNode *sec=left->next, *sec_last=right->next;
            left->next=right;
            right->next=sec;
            left=sec;
            right=sec_last;
        }
    }
};