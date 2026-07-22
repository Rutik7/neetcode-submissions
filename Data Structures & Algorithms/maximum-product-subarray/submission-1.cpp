class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            int product = 1;
            for(int j = i; j<nums.size(); j++)
            {
                product *= nums[j];
                result = max(result,product);
            }
        }

        return result;
    }
};
