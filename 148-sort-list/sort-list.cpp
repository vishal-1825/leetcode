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
};