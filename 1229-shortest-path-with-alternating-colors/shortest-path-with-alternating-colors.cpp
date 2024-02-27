struct Node
{
    int distance;
    int node;
    int color;
};

struct compare
{
    bool operator()(Node a, Node b)
    {
        return (a.distance < b.distance);
    }
};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)
    {
        vector<int> dist(n, INT_MAX);
        dist[0]=0;
        
        vector<bool> redVisited(n, false), blueVisited(n, false);
        
        unordered_map<int, vector<int>> redGraph, blueGraph;
        for (auto& r: redEdges)
            redGraph[r[0]].push_back(r[1]);
        for (auto& b: blueEdges)
            blueGraph[b[0]].push_back(b[1]);
        
        queue<Node> pendingNodes;
        pendingNodes.push({0, 0, 0});
        redVisited[0]=true;
        blueVisited[0]=true;
        while (!pendingNodes.empty())
        {
            int distance=pendingNodes.front().distance;
            int node=pendingNodes.front().node;
            int color=pendingNodes.front().color;
            pendingNodes.pop();
            
            if (distance<dist[node]) dist[node]=distance;

            // 0 - start, 1 - red, 2 - blue
            if (color==0 || color==1) // here color is color of previous edge
            {
                for (auto& nei: blueGraph[node])
                {
                    if (blueVisited[nei]) continue;
                    blueVisited[nei]=true;
                    pendingNodes.push({distance+1, nei, 2});
                }
            }
            if (color==0 || color==2)
            {
                for (auto& nei: redGraph[node])
                {
                    if (redVisited[nei]) continue;
                    redVisited[nei]=true;
                    pendingNodes.push({distance+1, nei, 1});
                }
            }
        }

        for (int i=0; i<n; i++)
        {
            if (dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};