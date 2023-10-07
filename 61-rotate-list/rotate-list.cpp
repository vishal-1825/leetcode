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
    int getLength(ListNode *head)
    {
        ListNode *temp=head;
        int i=0;
        for (; temp!=NULL; i++)
            temp=temp->next;
        return i;
    }
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head==NULL || head->next==NULL) return head;

        int n=getLength(head);
        k=k%n;
        
        ListNode *temp=head;
        for (int i=0; i<n-k-1; i++)
            temp=temp->next;
        
        if (temp==NULL || temp->next==NULL) return head;

        ListNode *newHead=temp->next;
        temp->next=NULL;

        temp=newHead;
        while (temp!=NULL && temp->next!=NULL) temp=temp->next;
        if (temp) temp->next=head;

        return newHead;
    }
};