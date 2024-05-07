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
    // pair<int, ListNode*> doubleItHelper(ListNode* head)
    // {
    //     if (!head) return {0, NULL};

    //     pair<int, ListNode*> rightAns = doubleItHelper(head->next);
    //     int mul=head->val*2+rightAns.first;
    //     ListNode *newHead = new ListNode(mul%10);
    //     newHead->next=rightAns.second;
    //     return {mul/10, newHead};
    // }
    // ListNode* doubleIt(ListNode* head)
    // {
    //     pair<int, ListNode*> ans = doubleItHelper(head);
    //     if (ans.first==0) return ans.second;
    //     ListNode *newHead = new ListNode(ans.first);
    //     newHead->next=ans.second;
    //     return newHead;
    // }
    ListNode *reverse(ListNode* head)
    {
        if (!head) return head;

        ListNode *prev=NULL, *cur=head, *nxt=head;
        while (cur!=NULL)
        {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head)
    {
        ListNode *revhead = reverse(head);
        ListNode *temp=revhead, *doublehead=NULL, *doubletail=NULL;
        int carry=0;
        while (temp!=NULL)
        {
            int val=temp->val*2+carry;
            ListNode *node = new ListNode(val%10);
            if (doublehead==NULL)
            {
                doublehead=node;
                doubletail=node;
            }
            else
            {
                doubletail->next=node;
                doubletail=doubletail->next;
            }
            carry=val/10;
            temp=temp->next;
        }
        if (carry!=0)
        {
            ListNode *node = new ListNode(carry);
            doubletail->next=node;
            doubletail=doubletail->next;
        }
        doublehead=reverse(doublehead);
        return doublehead;
    }
};