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
/*
    ListNode* sortList(ListNode* head)
    {
        if (!head || head->next==NULL) return head;

        ListNode *newHead=sortList(head->next);
        if (!newHead || head->val<=newHead->val)
        {
            head->next=newHead;
            return head;
        }
        else
        {
            ListNode *temp=newHead;
            while (temp->next && temp->next->val<head->val)
                temp=temp->next;
            ListNode *nxt=temp->next;
            temp->next=head;
            head->next=nxt;
            return newHead;
        }
    }
*/
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next) return head;

        ListNode *slow=head, *fast=head->next->next;
        while (fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *right=sortList(slow->next);
        slow->next=NULL;
        ListNode *left=sortList(head);


        if (!left) return right;
        if (!right) return left;
        
        ListNode *newHead = new ListNode(0);
        ListNode *temp=newHead;
        while (left && right)
        {
            if (left->val<=right->val)
            {
                temp->next=left;
                left=left->next;
            }
            else
            {
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        if (left) temp->next=left;
        if (right) temp->next=right;
        
        head=newHead->next;
        delete newHead;
        return head;
    }
};