class Solution {
public:
//Recursive
    long long f(int i,int n,vector<vector<int>>& questions){
        if(i>=n){
            return 0;
        }
        int points=questions[i][0];
        int brainpower=questions[i][1];
        int solve=points+f(i+brainpower+1,n,questions);
        int not_solve=f(i+1,n,questions);
        return max(solve,not_solve);
    }
//
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
       // return f(0,n,questions);  ---> recursive 
       //Tabulation
       vector<long long>dp(n+1);
       for(int i=n-1;i>=0;i--){
        int points=questions[i][0];
        int brainpower=questions[i][1];
         long long solve=points;
        if(i+brainpower+1<=n){
            solve+=dp[i+brainpower+1];
        }

       
       long long not_solve=dp[i+1];
        dp[i]=max(solve,not_solve);
       }
       return dp[0];
    }
};
