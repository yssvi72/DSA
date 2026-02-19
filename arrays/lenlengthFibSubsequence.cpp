class Solution {
public:
    unordered_map<int,int> find_index;
    
    int solve(int first, int second, vector<int>&arr,vector<vector<int>>&dp){
        int newele = first+second;
        if(find_index.find(newele) == find_index.end()){
            return 2;
        }
        int first_index = find_index[first];
        int second_index = find_index[second];
        if(dp[first_index][second_index] != -1){
            return dp[first_index][second_index];
        }

        return dp[first_index][second_index] =  1 + solve(second,newele,arr,dp);


    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i = 0; i<n; i++){
            find_index[arr[i]] = i;
        }
        int result = 0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                result = max(result,solve(arr[i],arr[j],arr,dp));
            }
        }
        return result>2 ? result:0;
    }
};
