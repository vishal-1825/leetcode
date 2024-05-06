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
    ListNode* removeNodes(ListNode* head)
    {
        stack<ListNode*> st;
        ListNode *temp = head;
        while (temp!=NULL)
        {
            while (!st.empty() && temp->val > st.top()->val)
                st.pop();
            st.push(temp);
            temp=temp->next;
        }

        stack<ListNode*> st1;
        while (!st.empty())
        {
            st1.push(st.top());
            st.pop();
        }
        
        head=NULL;
        temp=NULL;
        while (!st1.empty())
        {
            if (head==NULL)
            {
                head=st1.top();
                temp=st1.top();
            }
            else
            {
                temp->next=st1.top();
                temp=temp->next;
            }
            temp->next=NULL;
            st1.pop();
        }
        return head;
    }
};