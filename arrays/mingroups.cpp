class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // 1- Sort based on start time
        sort(intervals.begin(), intervals.end());

        // 2- Defining min heap to store the end time for each group
        priority_queue<int, vector<int>, greater<int>> pq;

        // 3-Iterating through each interval

        for (vector<int> interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // if the min value in heap(end time) is less than start means it is
            // not intersecting
            if (!pq.empty() && pq.top() < start) {
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size(); // 4- Size of heap==minimum no of groups required
    }
};
