#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        // Initialize variables
        int max_time = events[0][1];  // First event's time
        int result_button = events[0][0];  // First button as the initial result

        // Iterate through events
        for (int i = 1; i < events.size(); ++i) {
            int prev_time = events[i - 1][1];
            int curr_button = events[i][0];
            int curr_time = events[i][1];

            // Calculate the time difference
            int time_diff = curr_time - prev_time;

            // Update result if a longer time is found
            if (time_diff > max_time || (time_diff == max_time && curr_button < result_button)) {
                max_time = time_diff;
                result_button = curr_button;
            }
        }

        return result_button;
    }
};
