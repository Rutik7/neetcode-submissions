class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0 ;
        int end = n-1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(nums[mid] == target) return mid;

            // find which is part is sorted
            if(nums[start] <= nums[mid])
            {
                //left part is sorted 
                // will check target is lie in the that part

                if(nums[start]<= target && target<nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if(nums[mid]<target && target<=nums[end])
                {
                    start = mid+1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
