class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int h , l;
        int curr = nums[0];
        int count = 1;
        int sidx = 0;
        int eidx = 0;

        for(int i = 1;i<n;i++){
            if( __builtin_popcount(curr) == __builtin_popcount(nums[i])){
                count++;
            }else{
                eidx += count;
                // cout <<eidx<<" ";
                sort(nums.begin() + sidx,nums.begin() + eidx);
                count = 1;
                sidx = eidx;
                curr = nums[i];
                
            }
            
        }
         eidx += count;
         sort(nums.begin() + sidx,nums.begin() + eidx);

        for(int i = 1;i<n;i++){
           if(nums[i-1] > nums[i]) return false;
        }
        return true;
    }
};
