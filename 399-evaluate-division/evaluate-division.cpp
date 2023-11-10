class Solution {
public:
    // Absolutely no idea, checked the solution before solving
    // Try this again, it's important!!!!
    void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& gr, unordered_set<string>& visited, double& ans, double temp)
    {
        if (visited.find(node)!=visited.end()) return;

        visited.insert(node);
        if (node==dest)
        {
            ans=temp;
            return;
        }

        for (auto ne: gr[node])
            dfs(ne.first, dest, gr, visited, ans, temp*ne.second);
    }
    unordered_map<string, unordered_map<string, double>> getGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        unordered_map<string, unordered_map<string, double>> gr;
        for (int i=0; i<equations.size(); i++)
        {
            string num=equations[i][0], den=equations[i][1];
            double val=values[i];
            gr[num][den]=val;
            gr[den][num]=1.0/val;
        }
        return gr;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        unordered_map<string, unordered_map<string, double>> gr=getGraph(equations, values);
        vector<double> answer;

        for (auto query: queries)
        {
            string num=query[0], den=query[1];
            if (gr.find(num)==gr.end() || gr.find(den)==gr.end()) answer.push_back(-1.0);
            else
            {
                double ans=-1.0, temp=1.0;
                unordered_set<string> visited;
                dfs(num, den, gr, visited, ans, temp);
                answer.push_back(ans);
            }
        }
        return answer;
    }
};