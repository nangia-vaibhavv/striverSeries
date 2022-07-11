class KthLargest {
public:
     priority_queue <int, vector<int> , greater<int>> heap;
    int kth ;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(int n:nums) add(n);
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size()>kth)heap.pop();
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */