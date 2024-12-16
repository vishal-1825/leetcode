class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        // potential increase in ratio, pass, total  
        priority_queue<vector<double>> pq;
        for (int i=0; i<classes.size(); i++)
            pq.push({double(classes[i][0]+1)/double(classes[i][1]+1)-double(classes[i][0])/double(classes[i][1]), double(classes[i][0]), double(classes[i][1])});
        
        int extra=extraStudents;
        while (!pq.empty() && extra)
        {
            int pass=pq.top()[1], total=pq.top()[2];
            pq.pop();
            pq.push({double(pass+2)/double(total+2)-double(pass+1)/double(total+1), double(pass+1), double(total+1)});
            extra--;
        }

        double avg=0.0;
        while (!pq.empty())
        {
            avg+=(double(pq.top()[1])/double(pq.top()[2]));
            pq.pop();
        }
        avg/=double(classes.size());
        return avg;
    }
};