class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int sum = accumulate(rolls.begin(),rolls.end(),0);

        int diff = mean * (n+m) - sum ;
        if(diff<n) return {}; 
        vector<int>ans(n,0);

        if(diff/n < 6 ){
            int rem = diff%n;
            diff -= rem;

            for(int i = 0;i<n;i++){
                if(rem>0){
                    ans[i] = diff/n + 1;
                    rem--;
                }
                else ans[i] = diff/n;
            }
        }
        else if(diff/n==6 and diff%n==0){

                for(int i = 0;i<n;i++){
                    ans[i] =6;
                }
        }

        else return {};

        return ans;
    }
};
