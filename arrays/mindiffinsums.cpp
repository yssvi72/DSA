class Solution {
public:

  
    vector<long long>suf(vector<int>&nums){

        int totalsize = nums.size();
        int n = totalsize/3;
        vector<long long>ans(totalsize);
        long long currsum = 0;
        priority_queue<long long,vector<long long>,greater<long long>>pq;

        for(int i=totalsize-1;i>=n;i--){
            currsum += nums[i];
            pq.push(nums[i]);

            if(pq.size() > n){
                currsum = currsum - pq.top();
                pq.pop();
            }

            if(pq.size() == n){
                ans[i] = currsum;
            }
        }
        return ans;
    }



    long long minimumDifference(vector<int>& nums) {
        
        vector<long long>prefixsum = pref(nums);
        vector<long long>suffixsum = suf(nums);

        int totalsize = nums.size();
        int n = totalsize/3;
        long long ans = LLONG_MAX;

        for(int i=n-1;i<2*n;i++){
            long long diff = prefixsum[i] - suffixsum[i+1];
            ans = min(ans,diff);
        }
        return ans;

    }
};























