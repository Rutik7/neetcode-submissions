class Solution {
public:
    int findMin(vector<int> &nums) {
        // now I am gonna solve by optimize way
        // I will use Binary search for it
        // 

        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = nums[0];

        while(start <= end)
        {
            int mid = start + (end-start)/2;

            // now our array will spilt into 2 parts
            // start---mid and mid---end
            // find which part is sorted?
            // How 
            // if start < mid then our left part is sorted?
            // yes 

            if(nums[start]<=nums[mid])
            {
                ans = min(ans,nums[start]);
                start = mid+1;
            }
            else if(nums[mid]<nums[end])
            {
                // then our right part is sorted 
                ans = min(ans,nums[mid]);
                end = mid-1;
            }
        }

        return ans;
    }
};
