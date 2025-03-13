class Solution {
public:
    bool reduce(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> sum(n+1, 0);  
        
        for(int i = 0; i < k; i++) {
            sum[queries[i][0]] += queries[i][2];
            sum[queries[i][1] + 1] -= queries[i][2];
        }

        for(int i = 1; i < n; i++)
            sum[i] += sum[i-1];

        for(int i = 0; i < n; i++) {
            nums[i] = max(0, nums[i] - sum[i]);
            if(nums[i] != 0) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, h = queries.size();  
        int ans = -1;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            vector<int> temp = nums; 

            if (reduce(temp, queries, mid)) {  
                ans = mid;  
                h = mid - 1;  
            } else {  
                l = mid + 1;  
            }
        }
        return ans;
    }
};
