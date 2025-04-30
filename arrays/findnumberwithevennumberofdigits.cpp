class Solution {
public:
    int dig_cnt(int n){
        if(n == 0) return 1;

        int cnt = 0;

        while(n){
            cnt++;
            n/=10;
        }

        return cnt;
    }

    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int x:nums) if(dig_cnt(x)%2 == 0) ans++;
        return ans;
    }
};
