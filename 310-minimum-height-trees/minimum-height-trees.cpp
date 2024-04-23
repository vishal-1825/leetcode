class Solution {
public:
    // TLE
    // int bfs(vector<vector<int>>& graph, int root, int n)
    // {
    //     int h=0;
    //     queue<int> q;
    //     q.push(root);
    //     vector<bool> vis(n, false);
    //     vis[root]=true;
    //     while (!q.empty())
    //     {
    //         int sz=q.size();
    //         while (sz--)
    //         {
    //             int node=q.front();
    //             q.pop();

    //             for (int nei: graph[node])
    //             {
    //                 if (!vis[nei])
    //                 {
    //                     q.push(nei);
    //                     vis[nei]=true;
    //                 }
    //             }
    //         }
    //         h++;
    //     }
    //     return h-1;
    // }
    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    // {
    //     vector<vector<int>> graph(n);
    //     for (int i=0; i<edges.size(); i++)
    //     {
    //         graph[edges[i][0]].push_back(edges[i][1]);
    //         graph[edges[i][1]].push_back(edges[i][0]);
    //     }

    //     vector<int> hts(n);
    //     int minht=INT_MAX;
    //     for (int i=0; i<n; i++)
    //     {
    //         int h=bfs(graph, i, n);
    //         hts[i]=h;
    //         minht=min(minht, h);
    //     }

    //     vector<int> ans;
    //     for (int i=0; i<n; i++)
    //     {
    //         if (hts[i]==minht)
    //             ans.push_back(i);
    //     }
    //     return ans;
    // }

    // Understand why there can only be two possible roots at most
    // Keep removing all the leaf nodes (i.e nodes with degree one) till we end up with either 1 or 2 nodes
    // Note that when you remove a node, the it's edge with another node is removed and so the degree of the other node is decresed by 1
    // Edge case -> n=1 and no edges, return 0
    // Turns out that this approach is essentially topological sort (however, usually topological sort is done in directed graphs)
    // Time -> O(n), Space -> O(n)
    // 
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if (n==1) return {0}; // single node, no edges

        vector<int> degree(n, 0);
        vector<vector<int>> graph(n);
        for (int i=0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        queue<int> q;
        for (int node=0; node<n; node++)
        {
            if (degree[node]==1)
                q.push(node);
        }

        while (n>2)
        {
            int sz=q.size();
            n-=sz;
            while (sz--)
            {
                int node=q.front();
                q.pop();
                for (int nei: graph[node])
                {
                    degree[nei]--;
                    if (degree[nei]==1)
                        q.push(nei);
                }
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};