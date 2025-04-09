class Solution {
    public:
        int minOperations(vector<int>& a, int k) {
            int mn = *min_element(a.begin(), a.end());
            if (mn < k) return -1;
            
            unordered_set<int> s(a.begin(), a.end());
            return s.size() - (mn == k);
        }
    };
