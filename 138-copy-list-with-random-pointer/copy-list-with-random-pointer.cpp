/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        int i=0;
        unordered_map<Node*, int> index;
        unordered_map<int, Node*> nod;
        Node *temp=head, *head2, *temp2;

        if (temp==NULL) return NULL;

        while (temp!=NULL)
        {
            if (i==0)
            {
                head2 = new Node(temp->val);
                temp2=head2;
                index[head]=0;
                nod[0]=head2;
            }
            else
            {
                Node *n = new Node(temp->val);
                temp2->next=n;
                temp2=temp2->next;
                index[temp]=i;
                nod[i]=n;
            }
            temp=temp->next;
            i++;
        }

        temp=head;
        temp2=head2;
        while (temp!=NULL)
        {
            if (temp->random!=NULL) temp2->random=nod[index[temp->random]];
            else temp2->random=NULL;
            temp=temp->next;
            temp2=temp2->next;
        }
        return head2;
    }
};