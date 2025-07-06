class FindSumPairs {
public:
    unordered_map<int,int>mpp;
    vector<int>n1;
    vector<int>n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
        for(auto i:nums2)
            mpp[i]++;
    }
    
    void add(int index, int val) {
        mpp[n2[index]]--;
        n2[index]+=val;
        mpp[n2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for(auto i :n1)
                c+=mpp[tot-i];
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
