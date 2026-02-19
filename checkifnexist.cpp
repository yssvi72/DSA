class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
       
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(2*nums[i]==nums[j] || 2*nums[j]==nums[i] ) return true;
            }
        }
        return false;
    }
};
