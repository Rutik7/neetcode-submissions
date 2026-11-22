class KthLargest {
public:
    priority_queue<int, vector<int>,greater<int>> minheap;
    // int -  element type
    // vector<int> underlying container the continuous memory container to represent the binary heap tree
    // greater<int> comparator
    int size;

    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i: nums)
        {
            add(i);
        }
    }
    
    int add(int val) {
        // push in minheap
        minheap.push(val);
        if(minheap.size() > size) 
        {
            minheap.pop();        
        }

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */