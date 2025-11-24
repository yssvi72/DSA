class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long curr = 0;
        vector<bool> ans;
        for(int i = 0;i<nums.size();i++){
            curr = (((curr%5)*(2%5)) +nums[i]%5)%5;
            if(curr%5==0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
