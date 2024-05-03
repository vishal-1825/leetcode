class Solution {
public:
    int convert(string num)
    {
        int number=0;
        for (char c: num)
            number=number*10+(c-'0');
        return number;
    }
    int compareVersion(string version1, string version2)
    {
        vector<int> nums1, nums2;
        string num="";
        for (int i=0; i<=version1.length(); i++)
        {
            if (i==version1.length() || version1[i]=='.')
            {
                int number=convert(num);
                nums1.push_back(number);
                num="";
            }
            else num+=version1[i];
        }
        num="";
        for (int i=0; i<=version2.length(); i++)
        {
            if (i==version2.length() || version2[i]=='.')
            {
                int number=convert(num);
                nums2.push_back(number);
                num="";
            }
            else num+=version2[i];
        }

        int i;
        for (i=0; i<nums1.size() && i<nums2.size(); i++)
        {
            if (nums1[i]>nums2[i]) return 1;
            if (nums2[i]>nums1[i]) return -1;
        }
        for (; i<nums1.size(); i++)
        {
            if (nums1[i]!=0)
                return 1;
        }
        for (; i<nums2.size(); i++)
        {
            if (nums2[i]!=0)
                return -1;
        }
        return 0;
    }
};