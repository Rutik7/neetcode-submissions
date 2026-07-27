class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> umap;
        for (int i : nums) {
            umap[i]++;
        }

        priority_queue< 
            pair<int, int> , 
            vector<pair<int,int>> , 
            greater<pair<int,int>> 
            > pq;

        //now fill it in pq
        for(auto it: umap)
        {
            pq.push({it.second,it.first});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};