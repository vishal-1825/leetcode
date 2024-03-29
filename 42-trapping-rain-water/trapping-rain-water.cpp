class Solution {
public:
    int trap(vector<int>& height)
    {
        int n=height.size();
        if (n<=2) return 0;

        int ans=0, rightmax;
        vector<int> leftmax(n);
        
        leftmax[0]=height[0];
        for (int i=1; i<n; i++)
            leftmax[i]=max(leftmax[i-1], height[i]);
        
        rightmax=height[n-1];
        for (int i=n-2; i>0; i--)
        {
            rightmax=max(rightmax, height[i]);
            ans+=min(leftmax[i], rightmax)-height[i];
        }
        return ans;
    }
};