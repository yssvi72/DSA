class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        if(nums.size() == 1) return 1;

        int left = 0, subarrayLength = 0, check = 0;
        for(int right = 0; right < nums.size(); right++) {
            while((check & nums[right]) != 0) {
                check = check ^ nums[left];
                left++;
            }
            check = check | nums[right];
            subarrayLength = max(subarrayLength, right - left + 1);
        }
        return subarrayLength;
    }
};
