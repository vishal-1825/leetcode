/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root)
    {
        if (!root) return root;

        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        while (!pendingNodes.empty())
        {
            while (!pendingNodes.empty() && pendingNodes.front()!=NULL)
            {
                Node *f = pendingNodes.front();
                pendingNodes.pop();

                if (!pendingNodes.empty() && pendingNodes.front()!=NULL)
                    f->next=pendingNodes.front();
                
                if (f->left) pendingNodes.push(f->left);
                if (f->right) pendingNodes.push(f->right);
            }
            if (pendingNodes.size()==1) pendingNodes.pop();
            else if (!pendingNodes.empty())
            {
                pendingNodes.pop();
                pendingNodes.push(NULL);
            }
        }
        return root;
    }
};