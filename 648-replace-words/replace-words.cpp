class Solution {
public:
    string getRoot(string s, vector<string>& dictionary)
    {
        for (int i=0; i<dictionary.size(); i++)
        {
            if (s.substr(0, dictionary[i].length())==dictionary[i])
                return dictionary[i];
        }
        return "";
    }
    static bool comp(string s1, string s2)
    {
        return (s1.length() < s2.length());
    }
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        sort(dictionary.begin(), dictionary.end(), comp);
        string ans="", word="";
        sentence+=" ";
        for (int i=0; i<sentence.length(); i++)
        {
            if (sentence[i]==' ')
            {
                string root=getRoot(word, dictionary);
                if (root.length()==0) ans+=word;
                else ans+=root;
                ans+=" ";
                word="";
            }
            else word+=sentence[i];
        }
        ans.pop_back();
        return ans;
    }
};