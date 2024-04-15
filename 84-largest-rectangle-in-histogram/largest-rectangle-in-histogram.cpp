class Solution {
public:
    vector<int> leftsmall(vector<int>& heights, int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i=0; i<n; i++)
        {
            while (st.size()>1 && heights[st.top()]>=heights[i])
                st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> rightsmall(vector<int>& heights, int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(n);
        for (int i=n-1; i>=0; i--)
        {
            while (st.size()>1 && heights[st.top()]>=heights[i])
                st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights)
    {
        int n=heights.size(), ans=0;
        vector<int> ls=leftsmall(heights, n);
        vector<int> rs=rightsmall(heights, n);
        for (int i=0; i<n; i++)
            ans=max(ans, (rs[i]-ls[i]-1)*heights[i]);
        return ans;
    }
};