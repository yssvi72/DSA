class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        
        vector<int> prefixSum(n+1);//Prefix Sum of 'n+1' gaps.

        prefixSum[0]=startTime[0];
        for(int i=1;i<n;i++) prefixSum[i]=prefixSum[i-1]+(startTime[i]-endTime[i-1]);
        prefixSum[n]=prefixSum[n-1]+eventTime-endTime[n-1];

        int maxi=prefixSum[k];//length of first k consecutive gaps taken together.
        for(int i=1;i<n-k+1;i++) maxi=max(maxi, prefixSum[i+k]-prefixSum[i-1]);//find maximum length achievable by taking k consecutive gaps together.

        return maxi;
    }
};
