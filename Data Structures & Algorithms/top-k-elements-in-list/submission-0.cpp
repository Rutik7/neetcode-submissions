class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> umap;
        for(int i: nums)
        {
            umap[i]++;
        }

        // now I have key and frequency;
        // put in vector
        vector<pair<int,int>> vec;

        for(auto it: umap)
        {
            vec.push_back(it);
        }

        // now I solving this by sorting the frequencies of each elements 

        sort(vec.begin(),vec.end(), [](const pair<int,int> &a , const pair<int,int> &b ){ return a.second > b.second ;});

        for(int i = 0 ;i<k;i++)
        {
            result.push_back(vec[i].first);
        }
        return result;
    }
};
