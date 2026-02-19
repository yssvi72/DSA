class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> mp(10, 0); // frequency of input digits
        for (const auto& d : digits) ++mp[d];

        vector<int> res;

        for (int o = 100; o <= 998; o += 2) { // iterate only even numbers
            int tmp = o;
            vector<int> cur(10, 0); // frequency of current number

            while (tmp) {
                int k = tmp % 10;
                ++cur[k];
                tmp /= 10;
            }

            bool valid = true;
            for (int j = 0; j <= 9; ++j) {
                if (cur[j] > mp[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) res.push_back(o);
        }

        return res;
    }
};
