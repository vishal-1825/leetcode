class Solution {
public:
    bool isValid(vector<int>& derived, int first)
    {
        int n=derived.size(), next=first^derived[0];
        for (int i=1; i<n; i++)
            next=next^derived[i];
        return (next==first);
    }
    bool doesValidArrayExist(vector<int>& derived)
    {
        bool check = isValid(derived, 0) || isValid(derived, 1);
        return check;
    }
};