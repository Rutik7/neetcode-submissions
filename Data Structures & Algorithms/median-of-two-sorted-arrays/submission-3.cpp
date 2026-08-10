class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //binary search on smaller array

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1>n2)
        {
            return findMedianSortedArrays(nums2,nums1);
        }

        //find the leftsize = total elements should be present
        //in the left partition after we split the two arrays.

        int leftsize = (n1 + n2 + 1)/2;
        //Why + 1
        // for the both condition odd and even numbers of element

        // we apply only binary serach on nums1.
        int start = 0;
        int end = n1;

        while(start<=end)
        {
            int cut1 = start + (end - start)/2; // cut1 for nums1;
            
            // so our cut2 on nums2 will be
            int cut2 = leftsize - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // check our partition is correct or not
            // correct partition found
            if(l1 <= r2 && l2 <= r1)
            {
                //correct partion
                //for odd
                if((n1+n2) % 2 == 1)
                {
                    return max(l1,l2);
                }
                else //for even
                {
                    return (max(l1,l2) + min(r1,r2)) / 2.0 ; 
                }
            }
            // incorrect partition
            else if(l1 > r2) // that means we have taken too many elements from nums1
            {
                end = cut1 - 1;
            }
            else //l2 > r1 cut1 is too far left
            {
                start  = cut1 + 1;
            }
        }

        return 0;
    }
};