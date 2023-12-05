class Solution {
public:
    // Referred to solution, supposed to be hard not medium
    int countCompleteSubstrings(string word, int k)
    {
        int n=word.length();
        vector<vector<int>> freq(n+1, vector<int>(26, 0));
        // freq of characters start getting added from 1 instead of 0 for easier implementation
        for (int i=0; i<n; i++)
        {
            freq[i+1]=freq[i];
            freq[i+1][word[i]-'a']++;
        }

        int expectedLeft=0, actualLeft, ans=0;
        for (int i=0; i<n; i++) // iterating through string
        {
            if (i>=1 && abs(word[i]-word[i-1])>2)
                expectedLeft=i;
            
            for (int j=1; j<=26; j++) // taking substring lengths k, 2k, 3k...25k, 26k
            {
                actualLeft=i-j*k+1;
                if (actualLeft<expectedLeft) break; // if expected < actual it means that we enter the region where
                // diff between adjacent characters is greater than 2 which obviously is not a valid substring

                bool flag=true;
                for (char c='a'; c<='z'; c++) // check if freq of characters in the substring is k
                {
                    int fq = freq[i+1][c-'a'] - freq[actualLeft][c-'a'];
                    if (fq!=0 && fq!=k)
                    {
                        flag=false;
                        break;
                    }
                }
                if (flag) ans++;
            }
        }
        return ans;
    }
};