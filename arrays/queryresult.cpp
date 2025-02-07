class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballToColor;  // ball number -> color
        unordered_map<int, int> colorToBalls; // colors -> number of balls

        vector<int> ans;
        int n = queries.size();

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if (ballToColor.find(ball) != ballToColor.end()) {
                int oldColor = ballToColor[ball];
                colorToBalls[oldColor]--;
                if (colorToBalls[oldColor] == 0)
                    colorToBalls.erase(oldColor);
            }
            ballToColor[ball] = color;
            colorToBalls[color]++;
            ans.push_back(colorToBalls.size());
        }

        return ans;
    }
};
