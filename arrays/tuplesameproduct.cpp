

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        if (nums.size() < 4) return 0;
        unordered_map<int, int> countProduct;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                countProduct[nums[i]*nums[j]]++;
            }
        }

        int res = 0;

        for (auto [_, prod] : countProduct) {
            res += (prod - 1) * prod * 4;
        }

        return res;
    }
};
