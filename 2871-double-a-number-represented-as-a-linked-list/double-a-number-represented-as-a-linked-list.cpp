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
    pair<int, ListNode*> doubleItHelper(ListNode* head)
    {
        if (!head) return {0, NULL};

        pair<int, ListNode*> rightAns = doubleItHelper(head->next);
        int mul=head->val*2+rightAns.first;
        ListNode *newHead = new ListNode(mul%10);
        newHead->next=rightAns.second;
        return {mul/10, newHead};
    }
    ListNode* doubleIt(ListNode* head)
    {
        pair<int, ListNode*> ans = doubleItHelper(head);
        if (ans.first==0) return ans.second;
        ListNode *newHead = new ListNode(ans.first);
        newHead->next=ans.second;
        return newHead;
    }
};