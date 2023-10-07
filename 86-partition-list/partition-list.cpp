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
    ListNode* partition(ListNode* head, int x)
    {
        if (!head || head->next==NULL) return head;

        int n=0, i;
        vector<ListNode*> node;
        ListNode *temp=head;
        head=NULL;
        while (temp)
        {
            node.push_back(temp);
            temp=temp->next;
            n++;
        }

        i=0;
        while (i<n)
        {
            while (i<n && node[i]->val>=x) i++;

            if (i<n)
            {
                head=node[i];
                temp=head;
                while (i<n)
                {
                    if (node[i]->val<x)
                    {
                        temp->next=node[i];
                        temp=temp->next;
                    }
                    i++;
                }
            }
        }

        i=0;
        while (i<n)
        {
            while (i<n && node[i]->val<x) i++;

            if (i<n)
            {
                if (head)
                {
                    temp->next=node[i];
                    temp=temp->next;
                }
                else
                {
                    head=node[i];
                    temp=head;
                }
                while (i<n)
                {
                    if (node[i]->val>=x)
                    {
                        temp->next=node[i];
                        temp=temp->next;
                    }
                    i++;
                }
            }
        }
        temp->next=NULL;

        return head;
    }
*/
    ListNode* partition(ListNode* head, int x)
    {
        ListNode *small_head = new ListNode(-101);
        ListNode *large_head = new ListNode(-101);
        ListNode *small=small_head, *large=large_head;

        while (head)
        {
            if (head->val<x)
            {
                small->next=head;
                small=small->next;
                head=head->next;
                small->next=NULL;
            }
            else
            {
                large->next=head;
                large=large->next;
                head=head->next;
                large->next=NULL;
            }
        }

        if (small_head->next!=NULL)
        {
            small->next=large_head->next;
            return small_head->next;
        }
        else return large_head->next;
    }
};