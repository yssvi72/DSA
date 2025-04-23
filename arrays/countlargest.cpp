class Solution {
public:
    int countLargestGroup(int n) {
        // since max n is 10^4 so max sum comes from 9999 which is 36.
        vector<int> sumCounter = vector<int>(37, 0);
        int maxCount = 0;
        int answer = 0;
        int digitSum;
        for (int i = 1; i <= n; ++i) {
            digitSum = getDigitSum(i);
            sumCounter[digitSum]++;
            if (maxCount < sumCounter[digitSum]) {
                maxCount = sumCounter[digitSum];
                answer = 1;
            } else if (maxCount == sumCounter[digitSum]) {
                answer++;
            }
        }
        return answer;
    }
private:
    inline int getDigitSum(int x) {
        int ans = 0;
        while (x != 0) {
            ans += x%10;
            x /= 10;
        }
        return ans;
    }
};
