class Solution {
public:
    void helper(vector<int>& candidates, int target,int index,int sum,vector<int>& local_ans,set<vector<int>>& result) {
        if(sum == target) 
        {
            result.insert(local_ans);
            return;
        }
        //here my 1st base condition index reach the last
        if(index == candidates.size()) return;

        // sum is greater than target
        if(sum > target) return;

        for(int i = index;i<candidates.size();i++)
        {
            if(sum + candidates[i] > target)
                break;

            if(i > index && candidates[i] == candidates[i-1]) continue; 

            // pick the number at the index
            local_ans.push_back(candidates[i]);
            
            helper(candidates,target,i+1,sum+candidates[i],local_ans,result);

            local_ans.pop_back();

        }        
        



    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> result;
        vector<int> local_ans;
        // use set to remove the duplicates
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,0,local_ans,result);
        vector<vector<int>> Iresult(result.begin(),result.end());

        return Iresult;
    }
};