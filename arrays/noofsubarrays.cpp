class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
    int oddCount = 0, evenCount = 1;  
    int sum = 0, result = 0;

    for (int num : arr) {
        sum ^= num;  // Alternative to sum += num (but only optimal for XOR-based problems)
        result = (result + ((sum & 1) ? evenCount : oddCount)) % MOD;
        (sum & 1) ? oddCount++ : evenCount++;
    }

    return result;
        }
};
