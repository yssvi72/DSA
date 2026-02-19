class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long start=0;
        long long count=0;
        long long curr=0;

        for(long long end=0;end<nums.size();end++){
            curr+=nums[end];
            while( curr*(end-start+1)>=k){
                curr-=nums[start];
                start+=1;
            }
            count+=(end-start+1);
        }
        return count;
    }
};
