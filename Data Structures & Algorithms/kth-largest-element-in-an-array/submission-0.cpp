class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap(nums.begin(),nums.end());

        // pop first k-1 element
        for(int i = 1;i<k;i++)
        {
            maxheap.pop();
        }

        return maxheap.top();
    }
};