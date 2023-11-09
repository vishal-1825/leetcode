/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node, Node* clone, unordered_map<int, Node*>& visited)
    {
        if (!node) return clone;
        if (visited.find(node->val)!=visited.end()) return visited[node->val];

        clone->val=node->val;
        visited[clone->val]=clone;
        for (auto& n:node->neighbors)
        {
            Node *cl = new Node();
            cl = cloneGraph(n, cl, visited);
            clone->neighbors.push_back(cl);
        }
        return clone;
    }
    Node* cloneGraph(Node* node)
    {
        if (!node) return node;

        unordered_map<int, Node*> visited;
        Node *clone = new Node();
        return clone=cloneGraph(node, clone, visited);
    }
};