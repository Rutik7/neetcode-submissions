class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];

        int n = nums.size();

        for(int i = 1;i<n;i++)
        {
            if(ans>nums[i])
            {
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};
