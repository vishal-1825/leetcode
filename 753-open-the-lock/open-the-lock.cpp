class Solution {
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> visited;
        for (string d: deadends)
            visited.insert(d);
        if (visited.find("0000")!=visited.end()) return -1;
        visited.insert("0000");
        
        queue<string> q;
        q.push("0000");
        
        int turns=0;
        while (!q.empty())
        {
            int sz=q.size();
            while (sz--)
            {
                string lock=q.front();
                q.pop();

                if (lock==target) return turns;

                for (int i=0; i<4; i++)
                {
                    char original = lock[i];
                    char minus = (lock[i]=='0' ? '9' : lock[i]-1);
                    char plus = (lock[i]=='9' ? '0' : lock[i]+1);

                    lock[i]=minus;
                    if (visited.find(lock)==visited.end())
                    {
                        q.push(lock);
                        visited.insert(lock);
                    }

                    lock[i]=plus;
                    if (visited.find(lock)==visited.end())
                    {
                        q.push(lock);
                        visited.insert(lock);
                    }

                    lock[i]=original;
                }
            }
            turns++;
        }
        return -1;
    }
};