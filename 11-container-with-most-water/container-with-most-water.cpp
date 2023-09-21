class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size(), i=0, j=n-1, ans=0, h;

        while (i<j)
        {
            h=min(height[i], height[j]);
            ans=max(ans, h*(j-i));

            if (height[i]==height[j])
            {
                if (height[i+1]>height[j-1]) i++;
                else j--;
            }
            else if (h==height[i]) i++;
            else j--;
        }
        return ans;
    }
};