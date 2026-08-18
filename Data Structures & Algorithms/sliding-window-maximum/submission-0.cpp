class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int n = nums.size();
        int right = 0;

        vector<int> result;
        
        //push 1st k elements with index in priority queue

        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<k ;i++)
        {
            pq.push({nums[i],i});
        }
            result.push_back(pq.top().first);

        // now slide the window

        for(int right = k ; right<n;right++)
        {
            pq.push({nums[right] , right}) ;

            while( pq.top().second <= right - k)  
            {
                pq.pop();
            }

            result.push_back(pq.top().first);
        }

        return result;

        
    }
};