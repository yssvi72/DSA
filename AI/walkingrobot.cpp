class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, dir = 0; // north
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}; // north, east, south, west
        set<pair<int, int>> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }
        int maxDist = 0;
        for (auto& command : commands) {
            if (command == -2) {
                dir = (dir + 3) % 4; // turn left
            } else if (command == -1) {
                dir = (dir + 1) % 4; // turn right
            } else {
                for (int i = 0; i < command; i++) {
                    int newX = x + dx[dir], newY = y + dy[dir];
                    if (obstacleSet.find({newX, newY}) == obstacleSet.end()) {
                        x = newX, y = newY;
                    }
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }
        return maxDist;
    }
};
