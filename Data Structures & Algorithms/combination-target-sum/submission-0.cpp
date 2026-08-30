class Solution {
public:
    void helper(vector<int>& candidates, int target, int sum, int index , vector<vector<int>>& ans,vector<int>&localans)
    {
        if(index == candidates.size()) return;
        if(sum>target) return;
        if(sum == target) 
        {
            ans.push_back(localans);
            return;
        }

        localans.push_back(candidates[index]); // choose this candidate
        helper(candidates,target,sum+candidates[index],index,ans,localans);

        // not choose this candidate
        localans.pop_back();
        helper(candidates,target,sum,index+1,ans,localans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> localans;
        helper(candidates,target,0,0,ans,localans);
        return ans;
    }
};