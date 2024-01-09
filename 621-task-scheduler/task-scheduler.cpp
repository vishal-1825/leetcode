class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> fq(26, 0), prev(26, -1);
        for (auto& t: tasks)
            fq[t-'A']++;
        
        int tasksCount=tasks.size(), ans=0;
        while (tasksCount)
        {
            char task='0';
            int f=0;
            for (int i=0; i<26; i++)
            {
                if (fq[i]>f && (prev[i]==-1 || ans-prev[i]>=n))
                {
                    task=char(i+'A');
                    f=fq[i];
                }
            }
            if (task!='0')
            {
                fq[task-'A']--;
                prev[task-'A']=ans+1;
                tasksCount--;
            }
            ans++;
        }
        return ans;
    }
};