class Solution
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int n=position.size(), ans=0;
        double max_time=0;
        map<int, double> time;

        for (int i=0; i<n; i++)
            time[position[i]]=(target-position[i])/(double)speed[i];
        
        for (auto t=time.rbegin(); t!=time.rend(); t++)
        {
            if (t->second>max_time)
            {
                max_time=t->second;
                ans++;
            }
        }
        return ans;
    }
};