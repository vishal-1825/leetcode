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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode *dummy = new ListNode();
        dummy->next=list1;
        int c=0;
        ListNode *A, *B, *temp=dummy;
        while (temp!=NULL)
        {
            if (c==a) A=temp;
            if (c==b+1)
            {
                B=temp;
                break;
            }
            temp=temp->next;
            c++;
        }

        ListNode *tail2=list2;
        while (tail2!=NULL && tail2->next!=NULL)
            tail2=tail2->next;
        
        A->next=list2;
        if (B!=NULL) tail2->next=B->next;
        list1=dummy->next;
        delete dummy;
        return list1;
    }
};