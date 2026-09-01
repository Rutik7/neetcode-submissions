class Solution {
public:
    void helper(vector<int>& nums , int index , vector<vector<int>>& result, vector<int>& curr_subset)
    {
        if(index ==  nums.size()) 
        {
            // add current subset into result
            result.push_back(curr_subset);
            return;
        }

        
        // for nums[index] I have two choices 
        //pick
        curr_subset.push_back(nums[index]);
        helper(nums,index+1,result,curr_subset);

        //skip
        curr_subset.pop_back();
        helper(nums,index+1,result,curr_subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>subset;

        helper(nums,0,result,subset);
        return result;
    }
};