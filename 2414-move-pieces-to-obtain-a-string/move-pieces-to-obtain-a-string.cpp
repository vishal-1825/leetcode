class Solution {
public:
    bool canChange(string start, string target)
    {
        int n=start.length(), i=0, j=0;
        while (i<n || j<n)
        {
            while (i<n && start[i]=='_') i++;
            while (j<n && target[j]=='_') j++;
            
            if (i==n && j==n) break;
            if (i==n || j==n || start[i]!=target[j]) return false;
            if (start[i]=='L' && i<j) return false;
            else if (start[i]=='R' && i>j) return false;
            i++;
            j++;
        }
        return true;
    }
};