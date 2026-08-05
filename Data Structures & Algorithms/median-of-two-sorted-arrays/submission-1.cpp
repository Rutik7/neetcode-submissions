class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2)
    {
        int i = 0;
        int j = 0;

        vector<int> temp;

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] <= nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        // Remaining elements of nums1
        while(i < nums1.size())
        {
            temp.push_back(nums1[i]);
            i++;
        }

        // Remaining elements of nums2
        while(j < nums2.size())
        {
            temp.push_back(nums2[j]);
            j++;
        }

        return temp;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0;

        vector<int> temp = merge(nums1,nums2);

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
