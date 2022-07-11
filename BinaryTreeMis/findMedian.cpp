class MedianFinder {
    priority_queue<int> maxheap;//store sorted first half elements //for odd n it will have an extra element
    priority_queue<int,vector<int>,greater<int>> minheap;//store sorted second half elements
public:
    MedianFinder() {}
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(maxheap.size() < minheap.size()){    //if minheap has more element than max heap
            maxheap.push(minheap.top());
            minheap.pop();
        } 
    }
    
    double findMedian() {
        if(maxheap.size() > minheap.size()) return maxheap.top();
        return (maxheap.top() + minheap.top())/2.0;
    }
};