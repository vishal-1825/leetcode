class Solution {
public:
    // Convert this to a graph problem
    // Goal is to find the path in the graph such that all the edges of the graph are visited exactly once
    // If it's a completely cyclic graph, all the nodes will have indegree==outdegree so any node can be th start node
    // Otherwise there will be exactly one node that has indegree==outdegree-1, that is the start node
    // To find the required path, we start with the start node and try finding the end node recursively and get the reverse path
    // The end node will have outdegree+1==indegree
    // reversing it we get the answer
    unordered_map<int, queue<int>> graph;
    void EulerianPath(vector<int>& nodes, int node)
    {
        while (!graph[node].empty())
        {
            int neighbor=graph[node].front();
            graph[node].pop();
            EulerianPath(nodes, neighbor);
        }
        nodes.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs)
    {
        // unordered_map<int, queue<int>> graph;
        unordered_map<int, int> inOutDegree; // indegree - outdegree
        for (auto p: pairs)
        {
            graph[p[0]].push(p[1]);
            inOutDegree[p[1]]++;
            inOutDegree[p[0]]--;
        }
        int startNode=-1;
        for (auto node: inOutDegree)
        {
            if (node.second==-1)
            {
                startNode=node.first;
                break;
            }
        }
        if (startNode==-1) startNode=pairs[0][0];
        vector<int> nodes;
        EulerianPath(nodes, startNode);
        vector<vector<int>> ans;
        for (int i=nodes.size()-2; i>=0; i--)
            ans.push_back({nodes[i+1], nodes[i]});
        return ans;
    }
};

// 5,6 6,10 10,5 5,1 1,2 2,1 1,3 3,7 7,4 4,7

// 1: 2,3
// 2: 1
// 3: 7
// 4: 7
// 5: 1,6
// 6: 10
// 7: 4
// 10: 5