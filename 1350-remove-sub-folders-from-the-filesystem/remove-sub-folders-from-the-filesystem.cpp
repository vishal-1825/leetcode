class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (string f: folder)
        {
            if (ans.size()==0) ans.push_back(f);
            else
            {
                string prev = ans.back();
                if (f.length()>prev.length() && prev==f.substr(0, prev.length()) && f[prev.length()]=='/')
                    continue;
                else ans.push_back(f);
            }
        }
        return ans;
    }
};