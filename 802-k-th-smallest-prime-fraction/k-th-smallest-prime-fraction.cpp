class Solution {
public:
    // static bool compare(pair<int, int>& a, pair<int, int>& b)
    // {
    //     return (a.first*b.second<b.first*a.second);
    // }
    // vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    // {
    //     vector<pair<int, int>> fractions;
    //     for (int i=0; i<arr.size(); i++)
    //     {
    //         for (int j=i+1; j<arr.size(); j++)
    //             fractions.push_back({arr[i], arr[j]});
    //     }
    //     sort(fractions.begin(), fractions.end(), compare);
    //     return {fractions[k-1].first, fractions[k-1].second};
    // }

    // Time complexity O(nlog(m^2)), refer to editorial for explanation
    // O(1) space
    // vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    // {
    //     int n=arr.size();
    //     double left=0.0, right=1.0;
    //     while (left<=right)
    //     {
    //         double fraction=(left+right)/2.0, maxfraction=-1.0; // or mid
    //         int num=0, den=0, count=0, numi=0, deni=0;
    //         while (numi<n-1)
    //         {
    //             while (deni<n && arr[numi]>=fraction*arr[deni])
    //                 deni++;
    //             count+=(n-deni); // count of fractions smaller than (left+right)/2
    //             if (deni==n) break;
    //             double frac = double(arr[numi]) / double(arr[deni]);
    //             if (frac>maxfraction)
    //             {
    //                 num=arr[numi];
    //                 den=arr[deni];
    //                 maxfraction=frac;
    //             }
    //             numi++;
    //         }

    //         if (count==k) return {num, den}; // count of fractions smaller than (left+right)/2 is exactly k
    //         if (count>k) right=fraction;
    //         else left=fraction;
    //     }
    //     // Note that fraction is just greater than kth smallest fraction and not equal to it
    //     // It's value may not exist in the array
    //     return {};
    // }

    // Not intuitive coz we don't know that at each instant the smallest value will be between second smallest numerator/largest denominator and same numerator/second largest denominator 
    // Time -> O((n+k)logn), Space -> O(n)
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        int n=arr.size();
        for (int i=0; i<n; i++)
            pq.push({1.0*arr[i]/arr[n-1], {i, n-1}});
        while (k>1)
        {
            int numi=pq.top().second.first;
            int deni=pq.top().second.second;
            pq.pop();
            deni--;
            pq.push({1.0*arr[numi]/arr[deni], {numi, deni}});
            k--;
        }
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};