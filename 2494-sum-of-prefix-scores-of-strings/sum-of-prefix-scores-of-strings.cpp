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
};