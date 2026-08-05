class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0;

        vector<int> temp = nums1;
        temp.insert(temp.end(),nums2.begin(),nums2.end());

        sort(temp.begin(),temp.end());

        int N = temp.size();

        if(N%2 == 0)
        {
            //median 
            int mid = N/2;
            median = (temp[mid] + temp[mid-1]) / 2.0;
        }
        else
        {
            median = temp[N/2];
        }
        return median;
    }
};
