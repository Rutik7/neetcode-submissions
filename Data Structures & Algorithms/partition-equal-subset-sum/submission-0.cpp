class Solution {
public:
    bool issubsetoftarget(vector<int>& nums,int target,int index , int sum , vector<vector<int>>& dp )
    {
        if( target == sum ) 
        {
            return true;
        }

        if(sum > target) return false;

        if(index >= nums.size()) return false;

        if (dp[index][sum] != -1) return dp[index][sum];

        //pick the index number
        return dp[index][sum] = issubsetoftarget(nums , target, index+1, sum+nums[index], dp) ||
            issubsetoftarget(nums,target,index+1,sum , dp);


    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = nums[0];
        for(int i = 1;i<n;i++)
        {
            total += nums[i];
        }

        if( total % 2 == 1) return false;

        vector<vector<int>> dp (n,vector<int>((total/2)+1,-1));

        return issubsetoftarget(nums,total/2,0,0 , dp);
    }
};