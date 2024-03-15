class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> ans;
        int n = nums.size();
        vector<int> left_prod;
        vector<int> right_prod;
        int mult = nums[0];
        left_prod.push_back(nums[0]);
        for(int i = 1 ; i < n ; i++)
        {
            mult = mult * nums[i];
            left_prod.push_back(mult);
        }
        mult = nums[n-1];
        right_prod.push_back(nums[n-1]);
        for(int i = n-2 ; i >= 0 ; i--)
        {
            mult = mult * nums[i];
            right_prod.push_back(mult);
        }
        reverse(right_prod.begin(),right_prod.end());
        for(int i = 0 ; i < right_prod.size() ; i++)
        {
            if(i == 0)
                ans.push_back(right_prod[1]);
            else if(i == right_prod.size()-1)
                ans.push_back(left_prod[left_prod.size()-2]);
            else
                ans.push_back(left_prod[i-1]*right_prod[i+1]);
        }
        return ans;
    }
};
