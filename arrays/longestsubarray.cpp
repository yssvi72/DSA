class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x = *max_element(nums.begin(), nums.end());
        int l = 1;
        int temp_l = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == x)
                ++temp_l;
            else
                temp_l = 0;
            l = max(l, temp_l);


        }
        return l;
    }
};
