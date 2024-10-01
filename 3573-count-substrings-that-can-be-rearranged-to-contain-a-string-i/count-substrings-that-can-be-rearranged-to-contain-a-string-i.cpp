class Solution {
public:
    bool match(vector<int>& f1, vector<int>& f2)
    {
        for (int i=0; i<26; i++)
        {
            if (f1[i]<f2[i])
                return false;
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2)
    {
        if (word2.length()>word1.length()) return 0;
        
        long long ans=0;
        vector<int> f2(26, 0), f1(26, 0);
        for (char w: word2)
            f2[w-'a']++;

        int i=0, j=0;
        while (j<word1.length())
        {
            f1[word1[j]-'a']++;
            while (match(f1, f2))
            {
                ans+=(long long)(word1.length()-j);
                f1[word1[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};