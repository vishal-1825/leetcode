class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node)
    {
        // probabilities are always <=1
        // So the longer the path, lower the probability
        // Try to find shortest path using dijkstra'a algorithm
        vector<vector<pair<double, int>>> graph(n);
        for (int i=0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        
        vector<double> prob(n, 0);
        prob[start_node]=1.0;
        
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.push({prob[start_node], start_node});
        
        while (!pq.empty())
        {
            int node=pq.top().second;
            double this_prob=pq.top().first;
            pq.pop();

            if (node==end_node)
                return this_prob;

            for (auto g: graph[node])
            {
                double wt=g.first;
                int nei=g.second;
                if (prob[nei]<prob[node]*wt)
                {
                    prob[nei]=prob[node]*wt;
                    pq.push({prob[nei], nei});
                }
            }
        }
        return 0.0;
    }
};