class Solution {
public:

    void helper(vector<int>& nums , int index, vector<vector<int>>& result , vector<int>& currset ,int n)
    {
       
            result.push_back(currset);
        

        for(int i = index;i<n;i++)
        {
            //skip the duplicate
            if(i>index && nums[i] == nums[i-1]) continue;

            currset.push_back(nums[i]);
            helper(nums,i+1,result,currset,n);
            currset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currset;
        sort(nums.begin(),nums.end());
        helper(nums,0,result,currset,nums.size());

        return result;
    }
};