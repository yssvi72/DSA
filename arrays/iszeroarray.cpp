class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sub(n+1,0);

        for(int i = 0; i < queries.size(); i++)
        {
            sub[queries[i][0]] = sub[queries[i][0]] -1;
            sub[queries[i][1] + 1] = sub[queries[i][1] + 1] + 1;
        }
        for(int i = 1; i <= n; i++)
        {
            sub[i] = sub[i-1] + sub[i];
            // cout<<sub[i-1]<<" ";
            if(nums[i-1]+sub[i-1] > 0) return false;

        }
        return true;

    }
};
