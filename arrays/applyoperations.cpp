class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(i < n && j < n) {
            if(nums[i] == nums[j]) {
                nums[i] *= 2;
                nums[j] = 0;
            }
            i++;
            j++;
        }
        int index = 0;
        for(int k = 0; k < n; k++) {
            if(nums[k] != 0){
                swap(nums[k],nums[index]);
                index++;
            }
        }
        return nums;
    }
};
