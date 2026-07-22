class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];

        int answer  = nums[0];

        for(int i = 1;i<nums.size();i++)
        {
            // Need to think about it
            int prevMax = maxEnding;
            int prevMin = minEnding;

            maxEnding = max({nums[i],prevMax* nums[i], prevMin * nums[i]});
            minEnding = min({nums[i],prevMax* nums[i], prevMin * nums[i]});

            answer = max(answer,maxEnding);
        }

        return answer;
    }
};
