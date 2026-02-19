class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        long long left = 0;
        if (k % sum == 0) {
            return 0;
        } else {
            left = k - (k / sum) * sum;
        }
        for (int i = 0; i < n; i++) {
            left -= chalk[i];
            if (left < 0) {
                return i;
            } 
        }
        return -1;
    }
};
