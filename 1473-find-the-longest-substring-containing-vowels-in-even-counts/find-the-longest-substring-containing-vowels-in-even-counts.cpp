class Solution {
public:
    inline bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    int findTheLongestSubstring(string s)
    {
        // bitmasking, start with 0
        // Perform xor with vowel and xr with 0 in case f consonant
        // Say bitmask value is x at an index, if at y the bitmask is again x then in between the even number of vowels have been cancelled
        int bitmask=0, ans=0;
        unordered_map<int, int> firstIndex;
        firstIndex[0]=-1;
        for (int i=0; i<s.length(); i++)
        {
            if (isVowel(s[i])) bitmask = bitmask ^ s[i];
            else bitmask = bitmask ^ 0;
            if (firstIndex.find(bitmask)==firstIndex.end()) firstIndex[bitmask]=i;
            else ans=max(ans, i-firstIndex[bitmask]);
        }
        return ans;
    }
};