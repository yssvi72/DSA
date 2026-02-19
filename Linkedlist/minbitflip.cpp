class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int start_i = (1 << i) & start;
            int goal_i = (1 << i) & goal;
            ans = start_i == goal_i ? ans : ans + 1;
        }
        return ans;
    }
};
