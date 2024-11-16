class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=k-1;
        int coun=1;
        vector<int> ans(n-k+1,-1);

        for(int x=0;x<k-1;x++){
            if(nums[x+1]==nums[x]+1) coun++;
        }
        
        while(j<n){
            if(coun==k) ans[i]=nums[j];
            if(i<n-1 && nums[i+1]==nums[i]+1) coun--;
            if(j<n-1 && nums[j+1]==nums[j]+1) coun++;
            i++;
            j++;
        }
        return ans;
    }
};
