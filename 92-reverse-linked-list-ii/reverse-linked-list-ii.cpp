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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (head==NULL || left==right) return head;

        int i=1;
        bool endIsHead=false;
        ListNode *prev=NULL, *cur=NULL, *start=NULL, *end=NULL, *temp=head, *nxt=NULL;
        while (temp!=NULL && i<=right)
        {
            if (i+1==left) prev=temp;
            else if (i==left)
            {
                start=temp;
                cur=temp;
                nxt=cur->next;
            }
            else if (i==right) end=temp;

            temp=temp->next;
            i++;
        }

        if (prev!=NULL) prev->next=end;
        else endIsHead=true;
        
        while (cur!=NULL && cur!=end)
        {
            prev=cur;
            cur=nxt;
            nxt=cur->next;

            cur->next=prev;
        }
        start->next=nxt;

        if (endIsHead) return end;
        return head;
    }
};