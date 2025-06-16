class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1,min = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] > min){
                maxDiff = max(maxDiff,nums[i] - min);
            }
            else{
                min = nums[i];
            }
        }
        return maxDiff;
    }
};
