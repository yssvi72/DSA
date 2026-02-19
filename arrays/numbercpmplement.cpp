class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int times = 0;

        while(num > 0) {
            if(num % 2 == 0) {
                ans += pow(2, times); 
            }
            num = num/2;
            times++;
        }

        return ans;
    }
};
