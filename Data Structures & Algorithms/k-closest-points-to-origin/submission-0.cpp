class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxheap;
        vector<vector<int>> result;
        // now I need to calculate the distance of each points from origin 
        // and fill into the maxHeap;
        for(const auto& arr : points)
        {
            int x = arr[0];
            int y = arr[1];
            int distance = (x*x) + (y*y);

            maxheap.push({distance,{x,y}});
            if(maxheap.size()>k)
            {
                maxheap.pop();
            }
        }

        // now push into result
        while(!maxheap.empty())
        {
            const auto pair = maxheap.top();
            maxheap.pop();
            result.push_back({pair.second[0],pair.second[1]});
        }

        return result;
    }
};