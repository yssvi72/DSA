class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Step 1: Create a vector to store original nums and their mapped values
        vector<tuple<int, int, int>> mappedList;
        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            string n = "";
            for (char ch : s) {
                n += to_string(mapping[ch - '0']);
            }
            mappedList.push_back(make_tuple(nums[i], stoi(n), i));
        }

        // Step 2: Sort the vector based on the mapped values and original indices for stability
        sort(mappedList.begin(), mappedList.end(), [](const auto& a, const auto& b) {
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) < get<1>(b);
            } else {
                return get<2>(a) < get<2>(b);
            }
        });

        // Step 3: Create a result vector and fill it with the sorted original nums
        vector<int> sortedNums(nums.size());
        for (int i = 0; i < mappedList.size(); i++) {
            sortedNums[i] = get<0>(mappedList[i]);
        }

        return sortedNums;
    }
};
