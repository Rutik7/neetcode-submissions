class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // Always binary search on the smaller array
        if (m > n)
        {
            swap(nums1, nums2);
            swap(m, n);
        }

        int leftsize = (m + n + 1) / 2;

        // Search space for cut in nums1
        int low = 0;
        int high = m;

        while (low <= high)
        {
            int cut1 = low + (high - low) / 2;
            int cut2 = leftsize - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Correct partition found
            if (l1 <= r2 && l2 <= r1)
            {
                // Total elements are odd
                if ((m + n) % 2 == 1)
                {
                    return max(l1, l2);
                }
                else
                {
                    // Total elements are even
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }

            // nums1 partition is too far right
            else if (l1 > r2)
            {
                high = cut1 - 1;
            }

            // nums1 partition is too far left
            else
            {
                low = cut1 + 1;
            }
        }

        return 0.0; // This case will never happen for valid input
    }
};