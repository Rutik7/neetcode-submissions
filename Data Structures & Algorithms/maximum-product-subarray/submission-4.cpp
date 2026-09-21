class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //I will solve this by prefix and suffix
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int ans = nums[0];

        for(int i=0;i<n;i++)
        {
            if(prefix == 0)
                prefix=1;

            if(suffix == 0)
            {
                suffix = 1;
            }

            prefix *= nums[i];
            suffix *= nums[n-1-i];

            ans = max({ans,prefix,suffix});
        }


        return ans;
    }
};
