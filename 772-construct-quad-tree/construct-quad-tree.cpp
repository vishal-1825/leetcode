/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int x, int y, int n)
    {
        if (n==1) return new Node(grid[x][y], true);

        Node *tl=construct(grid, x, y, n/2);
        Node *tr=construct(grid, x, y+n/2, n/2);
        Node *bl=construct(grid, x+n/2, y, n/2);
        Node *br=construct(grid, x+n/2, y+n/2, n/2);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
        tl->val==tr->val&& bl->val==br->val && tl->val==br->val)
            return new Node(tl->val, true);
        return new Node(0, false, tl, tr, bl, br);
    }
    Node* construct(vector<vector<int>>& grid)
    {
        return construct(grid, 0, 0, grid.size());
    }
};