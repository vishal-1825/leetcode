class Solution {
public:
    string LCS(string str1, string str2, int i, int j)
    {
        vector<vector<string>> dp(str1.length()+1, vector<string>(str2.length()+1, ""));
        vector<string> dp0(str2.length()+1, ""), dp1(str2.length()+1, "");
        for (int i=str1.length()-1; i>=0; i--)
        {
            for (int j=str2.length()-1; j>=0; j--)
            {
                if (str1[i]==str2[j]) dp0[j]=str1[i]+dp1[j+1];
                else if (dp1[j].length()>=dp0[j+1].length()) dp0[j]=dp1[j];
                else dp0[j]=dp0[j+1];
            }
            dp1=dp0;
        }
        return dp0[0];
    }
    string shortestCommonSupersequence(string str1, string str2)
    {
        string str3 = LCS(str1, str2, 0, 0);

        string ans="";
        int i=0, j=0;
        for (char s3: str3)
        {
            while (i<str1.length() && str1[i]!=s3)
                ans+=str1[i++];
            i++;
            while (j<str2.length() && str2[j]!=s3)
                ans+=str2[j++];
            j++;
            ans+=s3;
        }
        while (i<str1.length())
            ans+=str1[i++];
        while (j<str2.length())
            ans+=str2[j++];
        return ans;
    }
    // string SCS(string str1, string str2, int i, int j, vector<vector<string>>& dp)
    // {
    //     if (i==str1.length() && j==str2.length()) return "";
    //     if (i==str1.length()) return str2.substr(j);
    //     if (j==str2.length()) return str1.substr(i);

    //     if (dp[i][j]!="-1") return dp[i][j];

    //     if (str1[i]==str2[j]) dp[i][j]=str1[i]+SCS(str1, str2, i+1, j+1, dp);
    //     else
    //     {
    //         string op1=str1[i]+SCS(str1, str2, i+1, j, dp);
    //         string op2=str2[j]+SCS(str1, str2, i, j+1, dp);
            
    //         if (op2.length()>0 && op2.length()<op1.length()) op1=op2;
    //         if (op1.length()>0) dp[i][j]=op1;
    //     }
    //     return dp[i][j];
    // }
    // string shortestCommonSupersequence(string str1, string str2)
    // {
    //     int n1=str1.length(), n2=str2.length();
    //     vector<vector<string>> dp(n1+1, vector<string>(n2+1, ""));
    //     // return SCS(str1, str2, 0, 0, dp);

    //     for (int i=0; i<n1; i++)
    //         dp[i][n2]=str1.substr(i);
    //     for (int j=0; j<n2; j++)
    //         dp[n1][j]=str2.substr(j);

    //     for (int i=n1-1; i>=0; i--)
    //     {
    //         for (int j=n2-1; j>=0; j--)
    //         {
    //             if (str1[i]==str2[j]) dp[i][j]=str1[i]+dp[i+1][j+1]; // SCS(str1, str2, i+1, j+1, dp);
    //             else
    //             {
    //                 string op1=str1[i]+dp[i+1][j]; // SCS(str1, str2, i+1, j, dp);
    //                 string op2=str2[j]+dp[i][j+1]; // SCS(str1, str2, i, j+1, dp);
                    
    //                 if (op2.length()>0 && op2.length()<op1.length()) op1=op2;
    //                 if (op1.length()>0) dp[i][j]=op1;
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }
};