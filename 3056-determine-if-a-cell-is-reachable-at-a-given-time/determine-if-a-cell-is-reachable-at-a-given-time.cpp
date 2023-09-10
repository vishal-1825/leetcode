typedef long long ll;
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        if (sx==fx && sy==fy) return (t==0 || t>1);
        else return (t>=max(abs(fx-sx), abs(fy-sy)));
    }
};