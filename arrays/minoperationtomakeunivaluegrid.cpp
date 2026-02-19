class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int mod = grid[0][0] % x;
        int sum=0;
        vector<int> value;

        for(auto it:grid){
            for(auto val:it){
              if (val% x != mod) {
                    return -1;
                }
                value.push_back(val);
                sum+=val;

            }
        }
    

        sort(value.begin(), value.end());

        int mini=INT_MAX;
        int psum=0;
        for(int i=0; i<value.size(); i++){
            int cnt;
            if(i==value.size()){
                cnt = (value[i]*i-psum)/x;
            }
            else cnt = (value[i]*i-psum)/x + (sum-psum-value[i] - (value.size()-i-1)*value[i])/x;
            mini = min(cnt,mini); 
            psum+=value[i];
        }
        return mini;


    }
};
