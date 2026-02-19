class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        vector<int> maxValues(events.size(), 0);
        maxValues[0] = events[0][2];
        for (int i = 1; i < events.size(); ++i) {
            maxValues[i] = max(maxValues[i - 1], events[i][2]);
        }
        int maxSum = maxValues.back();
        for (int i = events.size() - 1; i >= 0; --i) {
            int left = 0, right = i - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][1] < events[i][0]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (right >= 0) {
                maxSum = max(maxSum, events[i][2] + maxValues[right]);
            } else {
                maxSum = max(maxSum, events[i][2]);
            }
        }
        return maxSum;
    }
};
