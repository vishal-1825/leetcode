class TrieNode
{
    public:
    bool isTerminal;
    TrieNode* children[26];
    TrieNode()
    {
        isTerminal=false;
        for (int i=0; i<26; i++)
            children[i]=NULL;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode *temp = root;
        for (int i=0; i<word.length(); i++)
        {
            if (temp->children[word[i]-'a']==NULL)
                temp->children[word[i]-'a'] = new TrieNode();
            temp=temp->children[word[i]-'a'];
        }
        temp->isTerminal=true;
    }
    
    bool search(string word)
    {
        TrieNode *temp = root;
        for (int i=0; i<word.length(); i++)
        {
            if (temp->children[word[i]-'a']==NULL) return false;
            temp=temp->children[word[i]-'a'];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        for (int i=0; i<prefix.length(); i++)
        {
            if (temp->children[prefix[i]-'a']==NULL) return false;
            temp=temp->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */