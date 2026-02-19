class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> mergedMeetings;
        for(int i = 0; i < meetings.size(); i++){
            if(mergedMeetings.empty() or mergedMeetings.back()[1] < meetings[i][0]){
                mergedMeetings.push_back(meetings[i]);
            } else{
                mergedMeetings.back()[1] = max(meetings[i][1], mergedMeetings.back()[1]);
            }
        }
        int meetingDaysCount = 0;
        for(auto m : mergedMeetings){
            meetingDaysCount += (m[1] - m[0] + 1);
        }
        return days - meetingDaysCount;
    }
};
