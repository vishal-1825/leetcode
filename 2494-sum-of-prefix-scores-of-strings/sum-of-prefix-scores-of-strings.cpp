struct Node
{
    public:
    Node* children[26];
    int prefixCount=0;
};
class Trie
{
    public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (char c: word)
        {
            if (node->children[c-'a']==NULL)
                node->children[c-'a'] = new Node();
            node=node->children[c-'a'];
            node->prefixCount++;
        }
    }
    int getPrefixScoreSum(string word)
    {
        Node *node = root;
        int ans=0;
        for (char c: word)
        {
            node = node->children[c-'a'];
            ans+=node->prefixCount;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words)
    {
        vector<int> ans;
        Trie trie;
        for (string word: words)
            trie.insert(word);
        for (string word: words)
            ans.push_back(trie.getPrefixScoreSum(word));
        return ans;
    }
    // vector<vector<string>> getAllPrefixes(vector<string>& words)
    // {
    //     vector<vector<string>> prefixes(words.size());
    //     for (int i=0; i<words.size(); i++)
    //     {
    //         string w="";
    //         for (int j=0; j<words[i].length(); j++)
    //         {
    //             w+=words[i][j];
    //             prefixes[i].push_back(w);
    //         }
    //     }
    //     return prefixes;
    // }
    // vector<int> sumPrefixScores(vector<string>& words)
    // {
    //     vector<vector<string>> prefixes = getAllPrefixes(words);
    //     unordered_set<string> uniquePrefixes;
    //     for (auto p: prefixes)
    //     {
    //         for (string prefix: p)
    //             uniquePrefixes.insert(prefix);
    //     }
    //     unordered_map<string, int> score;
    //     for (string prefix: uniquePrefixes)
    //     {
    //         int sc=0;
    //         for (string word: words)
    //         {
    //             if (prefix.length()<=word.length() && prefix==word.substr(0, prefix.length()))
    //                 sc++;
    //         }
    //         score[prefix]=sc;
    //     }
    //     vector<int> ans;
    //     for (auto p: prefixes)
    //     {
    //         int scoreSum=0;
    //         for (string prefix: p)
    //             scoreSum+=score[prefix];
    //         ans.push_back(scoreSum);
    //     }
    //     return ans;
    // }  
};