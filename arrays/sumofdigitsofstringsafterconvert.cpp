class Solution {
public:
    long long sumOfDigits(long long num)
    {
        long long sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        long long num = 0;
        for (char c : s) {
            int pos = c - 'a' + 1;
            if (pos >= 10) {
                num += pos / 10 + pos % 10;
            } else {
                num += pos;
            }
        }
        for (int i = 1; i < k; ++i) {
            num = sumOfDigits(num);
        }
        return num;
    }
};
