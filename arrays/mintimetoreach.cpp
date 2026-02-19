class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<vector<int>>> timeTaken(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        timeTaken[0][0][0] = 0;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        pq.push({0, {0, 0, 0}});
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.empty()) {
            auto [currentTime, position] = pq.top();
            int x = position[0], y = position[1], toggle = position[2];
            pq.pop();
            if (currentTime > timeTaken[x][y][toggle]) continue;
            for (auto [dx, dy] : directions) {
                int newX = x + dx;
                int newY = y + dy;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int newTime = max(currentTime, moveTime[newX][newY]) + (toggle ? 2 : 1);
                    if (newTime < timeTaken[newX][newY][!toggle]) {
                        timeTaken[newX][newY][!toggle] = newTime;
                        pq.push({newTime, {newX, newY, !toggle}});
                    }
                }
            }
        }
        return min(timeTaken[n-1][m-1][0], timeTaken[n-1][m-1][1]);
    }
};
