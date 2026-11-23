class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // use of max heap
        priority_queue<int> maxheap(stones.begin(),stones.end());

        while(maxheap.size() > 1)
        {
            int first = maxheap.top();
            // pop the first
            maxheap.pop();
            int second = maxheap.top();
            maxheap.pop();

            // smash them
            if(first != second)
            {
                maxheap.push(first - second);
            }
        }

        if(maxheap.size() == 1)
        {
            return maxheap.top();
        }
        return 0;
    }
};