class MedianFinder {
    priority_queue<int> small;
    priority_queue<int,vector<int>, greater<int>> large;
public:
    MedianFinder() {
        
    }
    
   void addNum(int num) {
        // Add the number to the 'small' (max-heap) first
        small.push(num);

        // Balance Condition 1: Ensure smallest of large is not smaller than largest of small
        // If small is not empty, and large is not empty, AND
        // the top of small (largest in small) is greater than the top of large (smallest in large)
        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
        }

        // Balance Condition 2: Ensure heap sizes are balanced (difference at most 1)
        // If small heap has more than one extra element
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }
        // If large heap has more than one extra element
        if (large.size() > small.size() + 1) {
            small.push(large.top());
            large.pop();
        }
    }
    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        } 
        else if (large.size() > small.size()) {
            return large.top();
            }else {
            return (large.top() + small.top()) / 2.0;
        }}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */