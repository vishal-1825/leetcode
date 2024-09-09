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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        ListNode *ptr = head;
        int i=0, j=0, viscount=0;
        while (viscount<m*n)
        {
            // right
            while (j<n && !vis[i][j])
            {
                if (ptr)
                {
                    matrix[i][j] = ptr->val;
                    ptr = ptr->next;
                }
                viscount++;
                vis[i][j]=true;
                j++;
            }
            j--;
            i++;
            // down
            while (i<m && !vis[i][j])
            {
                if (ptr)
                {
                    matrix[i][j] = ptr->val;
                    ptr = ptr->next;
                }
                viscount++;
                vis[i][j]=true;
                i++;
            }
            i--;
            j--;
            // left
            while (j>=0 && !vis[i][j])
            {
                if (ptr)
                {
                    matrix[i][j] = ptr->val;
                    ptr = ptr->next;
                }
                viscount++;
                vis[i][j]=true;
                j--;
            }
            j++;
            i--;
            // up
            while (i>=0 && !vis[i][j])
            {
                if (ptr)
                {
                    matrix[i][j] = ptr->val;
                    ptr = ptr->next;
                }
                viscount++;
                vis[i][j]=true;
                i--;
            }
            i++;
            j++;
        }
        return matrix;
    }
};