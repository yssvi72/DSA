class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        int number=1;
        while(maximumBit--) number*=2;
        number--;
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]^nums[i];
        }
        for(int i=0; i<n; i++) prefix[i]^=number;
        reverse(prefix.begin(),prefix.end());
        return prefix;
    }
};
