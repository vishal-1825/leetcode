class Solution {
public: 
    bool isCycle(int node, vector<bool>& visited, vector<bool>& dfsvisited, vector<vector<int>>& adj)
    {
        visited[node]=true;
        dfsvisited[node]=true;
        for (auto nei : adj[node])
        {
            if (!visited[nei] && isCycle(nei, visited, dfsvisited, adj)) return true;
            else if (dfsvisited[nei]) return true;
        }
        dfsvisited[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false), dfsvisited(numCourses, false);
        for (auto p : prerequisites)
            adj[p[1]].push_back(p[0]);
        
        for (int i=0; i<numCourses; i++)
        {
            if (!visited[i] && isCycle(i, visited, dfsvisited, adj))
                return false;
        }
        return true;
    }
};