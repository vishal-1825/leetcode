class Solution {
public:
    class TrieNode
    {
        public:
        TrieNode *zero;
        TrieNode *one;
        TrieNode()
        {
            zero = NULL;
            one = NULL;
        }
    };

    class Trie
    {
        public:
        TrieNode *root;
        
        Trie()
        {
            root = new TrieNode();
        }

        void insert(int num)
        {
            TrieNode *temp=root;
            for (int i=31; i>=0; i--)
            {
                if ((num>>i & 1)==0)
                {
                    if (!temp->zero)
                    {
                        TrieNode *z = new TrieNode();
                        temp->zero=z;
                    }
                    temp=temp->zero;
                }
                else
                {
                    if (!temp->one)
                    {
                        TrieNode *o = new TrieNode();
                        temp->one=o;
                    }
                    temp=temp->one;
                }
            }
        }

        int findXOR(int num)
        {
            int ans=0;
            TrieNode *temp=root;
            for (int i=31; i>=0; i--)
            {
                if ((num>>i & 1)==0)
                {
                    if (temp->one)
                    {
                        ans+=(1<<i);
                        temp=temp->one;
                    }
                    else if (temp->zero) temp=temp->zero;
                }
                else
                {
                    if (temp->zero)
                    {
                        ans+=(1<<i);
                        temp=temp->zero;
                    }
                    else if (temp->one) temp=temp->one;
                }
            }
            return ans;
        }
    };

    int findMaximumXOR(vector<int>& nums)
    {
        Trie t;
        for (int i=0; i<nums.size(); i++)
            t.insert(nums[i]);

        int ans=0;
        for (int i=0; i<nums.size(); i++)
        {
            int x=t.findXOR(nums[i]);
            ans=max(ans, x);
        }
        return ans;
    }
};