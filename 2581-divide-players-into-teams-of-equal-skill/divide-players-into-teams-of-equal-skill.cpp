class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n=skill.size();
        long long sum=0, ans=0;
        unordered_map<int, int> fq;
        for (int s: skill)
        {
            sum+=s;
            fq[s]++;
        }
        if ((2*sum)%n!=0) return -1;
        int team=(2*sum)/n;
        cout << team << endl;
        for (auto f: fq)
        {
            while (fq[f.first]>0)
            {
                if (fq[team-f.first]==0) return -1;
                if (2*f.first==team && f.second==1) return -1;
                ans+=f.first*(team-f.first);
                fq[f.first]--;
                fq[team-f.first]--;
            }
        }
        return ans;
    }
};