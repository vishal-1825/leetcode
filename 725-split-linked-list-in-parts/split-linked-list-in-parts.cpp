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
    int length(ListNode* head)
    {
        int ans=0;
        ListNode *ptr = head;
        while (ptr)
        {
            ans++;
            ptr=ptr->next;
        }
        cout << ans << endl;
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        vector<ListNode*> ans;
        ListNode *cur = head, *nxt = head;
        if (nxt) nxt=head->next;
        int n=length(head), q=n/k, r=n%k;
        // r parts are of length q+1
        // k-r parts are of size q
        for (int i=0; i<r; i++)
        {
            ans.push_back(cur);
            for (int j=0; j<q; j++)
            {
                cur=cur->next;
                nxt=nxt->next;
            }
            if (cur) cur->next=NULL;
            cur=nxt;
            if (cur) nxt=cur->next;
        }
        for (int i=r; i<k; i++)
        {
            ans.push_back(cur);
            for (int j=0; j<q-1; j++)
            {
                if (cur) cur=cur->next;
                if (nxt) nxt=nxt->next;
            }
            if (cur) cur->next=NULL;
            cur=nxt;
            if (cur) nxt=cur->next;
        }
        return ans;
    }
};