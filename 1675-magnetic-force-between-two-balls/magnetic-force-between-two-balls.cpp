class Solution {
public:
    bool force(vector<int>& position, int m, int f)
    {
        int count=1, prev=position[0];
        for (int i=0; i<position.size(); i++)
        {
            if (position[i]-prev>=f)
            {
                count++;
                prev=position[i];
            }
            if (count==m)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m)
    {
        sort(position.begin(), position.end());
        int l=0, r=position[position.size()-1], ans=0;
        while (l<=r)
        {
            int mid=(l+r)/2;
            if (force(position, m, mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};

// 22 57 74 79