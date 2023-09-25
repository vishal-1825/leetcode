typedef long long ll;
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& mH)
    {
        ll i, n=mH.size(), ans=0;
        stack<ll> st; // stores 'index' of previous smaller element
        vector<ll> leftSmall(n), rightSmall(n);
        vector<ll> leftSum(n), rightSum(n);
        
        for (i=0; i<n; i++)
        {
            while (!st.empty() && mH[st.top()]>mH[i])
                st.pop();
            if (!st.empty()) leftSum[i]=leftSum[st.top()]+(i-st.top())*mH[i]; // if st.top() is index of smaller element
            else leftSum[i]=(i+1)*mH[i];  // if stack is empty i.e, no smaller element
            st.push(i);
        }
        while (!st.empty()) st.pop();
        
        for (i=n-1; i>=0; i--)
        {
            while (!st.empty() && mH[st.top()]>mH[i])
                st.pop();
            if (!st.empty()) rightSum[i]=rightSum[st.top()]+(st.top()-i)*mH[i];
            else rightSum[i]=(n-i)*mH[i];
            st.push(i);
        }
        
        for (i=0; i<n; i++)
            ans=max(ans, leftSum[i]+rightSum[i]-mH[i]);
        return ans;
    }
};