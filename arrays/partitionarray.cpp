class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size(),pivot);
        int a=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot) a++;}
        int x=0,y=nums.size()-a;
        for(int i:nums){
            if(i<pivot){
                ans[x]=i;
                x++;}
            else if(i>pivot){
                ans[y]=i;
                y++;}}
        return ans;
    }
};
