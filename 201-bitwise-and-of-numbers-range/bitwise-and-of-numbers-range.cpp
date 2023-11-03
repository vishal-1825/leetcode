typedef long long ll;
class Solution {
public:
    // couldn't do this yourself, try again
    int rangeBitwiseAnd(int left, int right)
    {
        int flipped=0;
        while (left!=right)
        {
            left=left>>1;
            right=right>>1;
            flipped++;
        }
        return (left<<flipped);
    }
};