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
    ListNode* deleteDuplicates(ListNode* head)
    {
        while (head!=NULL && head->next!=NULL && head->val==head->next->val)
        {
            int v=head->val;
            while (head!=NULL && head->val==v) head=head->next;
        }

        if (head!=NULL && head->next!=NULL)
        {
            ListNode *temp1=head, *temp2=head->next;

            while (temp2!=NULL)
            {
                int v=temp2->val;
                if (temp2->next==NULL || temp2->val!=temp2->next->val)
                {
                    temp1->next=temp2;
                    temp1=temp2;
                    if (temp2) temp2=temp2->next;
                }
                else
                {
                    while (temp2!=NULL && temp2->val==v)
                        temp2=temp2->next;
                }

            }
            if (temp1) temp1->next=temp2;
        }
        return head;
    }
};