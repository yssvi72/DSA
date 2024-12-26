class Solution {
public:


   void helper(vector<int>& nums, int target , int currentSum , int node ,int& total){

    // base case
    if(node == nums.size()){
        if(currentSum == target){
            total++;
        }
        return;
    }

    // case first - we want to add this number
    helper(nums,target,currentSum+nums[node],node+1,total);
    helper(nums,target,currentSum-nums[node],node+1,total);
     
   }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        int n = nums.size();
        helper(nums,target,0,0,total);
        return total;
    }
};
