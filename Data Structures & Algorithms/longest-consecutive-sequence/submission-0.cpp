class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        unordered_set<int> uset(nums.begin(),nums.end());
        
        int answer = 1;
        for(int i: uset)
        {
            if(uset.find(i-1) != uset.end())
            {
                continue;
            }
            int curr = 0;
            int currNum = i;
            while(uset.find(currNum++) != uset.end())
            {
                curr++;
            }

            answer = max(answer,curr);
        }
        return answer;
    }
};
