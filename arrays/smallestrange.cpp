class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        int n = nums.size();
        int max_element = INT_MIN;

        // Add the first element of each list to the heap
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], {i, 0}});
            max_element = max(max_element, nums[i][0]);
        }

        // Initialize the range
        int range_start = -1e5, range_end = 1e5;

        // Process the heap
        while (!pq.empty()) {
            auto [value, pos] = pq.top();
            pq.pop();
            int min_element = value;
            int row = pos.first;
            int col = pos.second;

            // Update the range if it's smaller than the current range
            if (max_element - min_element < range_end - range_start) {
                range_start = min_element;
                range_end = max_element;
            }

            // Add the next element from the same row to the heap
            if (col + 1 < nums[row].size()) {
                pq.push({nums[row][col + 1], {row, col + 1}});
                max_element = max(max_element, nums[row][col + 1]);
            }
            else break; // If we've reached the end of one list, stop
        }

        return {range_start, range_end};
    }
};
