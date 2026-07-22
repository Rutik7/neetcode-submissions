class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);

        // now fill the left
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        // fill the right
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        // compute the answer
        for (int i = 0; i < n; i++) {
            ans.push_back(left[i] * right[i]);
        }
        return ans;
    }
};
