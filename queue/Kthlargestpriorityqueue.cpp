class KthLargest {
private:
    std::priority_queue<int, vector<int>, greater<int>> heap_;
    int k_;

public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        // Sort in descending order. The reason this is needed is if nums.size() > k, we need to
        // ensure k largest elements will be stored in the heap_ when call next for loop
        sort(nums.begin(), nums.end(), greater<int>()); 
        // The reason i < min(k, static_cast<int>(nums.size())) is needed, is to cover all edge case:
        // if nums.size() > k, then k largest elemet will be pushed to the heap_
        // if nums.size() <= k, then all elements in nums will be pushed to heap_
        for (int i = 0; i < min(k, static_cast<int>(nums.size())); ++i) heap_.push(nums[i]);
    }
    int add(int val) {
        if (heap_.size() < k_) heap_.push(val);
        else {
            if (val > heap_.top()) {
                heap_.pop();
                heap_.push(val);
            }
        }
        return heap_.top();
    }
};
