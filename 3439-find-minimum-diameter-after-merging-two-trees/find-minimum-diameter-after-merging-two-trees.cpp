class Solution {
public:
    // diameter of graph = distance between 2 farthest nodes in graph
    // On merging to get minimum diameter, we need to create edge between centre nodes of the respective graphs
    // Let the diameters be d1 and d2
    // ceil(d1/2) and ceil(d2/2) will be the lengths of diameter from the centre node of each graph
    // Then we take 1 + ceil(d1/2) + ceil(d2/2) as the final answer
    // One problem with this is that this value can be less than the diameters f ne of the trees
    // So we take max(d1, d2, 1 + ceil(d1/2) + ceil(d2/2)) -> This value is the minimum at centre nodes of each tree
    void dfs(vector<vector<int>>& graph, int curNode, int parentNode, int dist, int& farthestNode, int& farthestDist)
    {
        if (dist>farthestDist)
        {
            farthestDist=dist;
            farthestNode=curNode;
        }

        for (int nei: graph[curNode])
        {
            if (nei==parentNode) continue;
            dfs(graph, nei, curNode, dist+1, farthestNode, farthestDist);
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2)
    {
        int n=edges1.size()+1, m=edges2.size()+1;
        vector<vector<int>> graph1(n), graph2(m);
        for (auto edge: edges1) // O(n)
        {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for (auto edge: edges2) // O(m)
        {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        int farthestNode1=0, farthestDist1=0;
        dfs(graph1, 0, -1, 0, farthestNode1, farthestDist1); // O(n) find farthest node from any node
        dfs(graph1, farthestNode1, -1, 0, farthestNode1, farthestDist1); // O(n) find farthest node from that node
        //                                                                  dist b/w them is the diameter

        int farthestNode2=0, farthestDist2=0;
        dfs(graph2, 0, -1, 0, farthestNode2, farthestDist2); // O(m)
        dfs(graph2, farthestNode2, -1, 0, farthestNode2, farthestDist2); // O(m)

        return max({farthestDist1, farthestDist2, 1+(farthestDist1+1)/2+(farthestDist2+1)/2});
    }
};