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
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        if (head==NULL || head->next==NULL || head->next->next==NULL) return {-1, -1};
        
        int i=1;
        vector<int> critical;
        ListNode *prev=head, *cur=head->next;
        while (cur->next!=NULL)
        {
            if (cur->val > prev->val && cur->val > cur->next->val) critical.push_back(i);
            else if (cur->val < prev->val && cur->val < cur->next->val) critical.push_back(i);
            i++;
            prev=prev->next;
            cur=cur->next;
        }
        sort(critical.begin(), critical.end());

        if (critical.size()<2) return {-1, -1};
        int c=critical.size();
        int minval=critical[c-1]-critical[0];
        int maxval=critical[c-1]-critical[0];
        for (int i=0; i<c-1; i++)
            minval=min(minval, critical[i+1]-critical[i]);
        return {minval, maxval};
    }
};