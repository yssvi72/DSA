class Solution {
public:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> maskToIndexMap;
        int mask = 0;
        int ans = 0;

        for (int i = 0; i < (int)s.length(); i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                mask ^= 1 << (s[i] - 'a');
            }

            if (mask == 0) {
                ans = i + 1;
            } else if (maskToIndexMap.find(mask) != maskToIndexMap.end()) {
                ans = max(ans, i - maskToIndexMap[mask]);
            } else {
                maskToIndexMap[mask] = i;
            }
        }

        return ans;
    }
};
