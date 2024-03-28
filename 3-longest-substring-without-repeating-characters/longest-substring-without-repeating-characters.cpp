class Solution {
public:
    int lengthOfLongestSubstring(string input)
    {
        int ans=0;
        unordered_map<char, int> fq;
        for (int i=0, j=0; j<input.length(); j++)
        {
            fq[input[j]]++;
            while (fq[input[j]]>1)
            {
                fq[input[i]]--;
                i++;
            }
            ans=max(ans, j-i+1);
        }
        return ans;
        // int n=s.size(), left=0, right=0, lbuf=0, ans=0;
        // unordered_set<char> st;
        // string buf="";

        // while (right<n)
        // {  
        //     while (right<n && st.find(s[right])==st.end())
        //     {
        //         buf+=s[right];
        //         lbuf++;
        //         ans=max(ans, lbuf);
                
        //         st.insert(s[right]);
        //         right++;
        //     }
        //     st.erase(s[left]);
        //     buf=buf.substr(1);
        //     lbuf--;
        //     left++;
        // }
        // return ans;
    }
};