class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int c = 0;
        int n = status.size();
        vector<int> boxes(n, 0);
        queue<int> q;
        for (int i : initialBoxes)
        {
            boxes[i] = 1;
            if (status[i]) q.push(i);
        }

        while (!q.empty())
        {
            int box = q.front();
            q.pop();
            c += candies[box];


            for (auto i : keys[box]) {
                if (status[i])
                    continue;
                status[i] = 1;
                if (boxes[i]) q.push(i);
            }

            for (auto i : containedBoxes[box]) {
                if (boxes[i]) continue;
                boxes[i] = 1;
                if(status[i]) q.push(i);
            }
        }
        return (c);
    }
};
