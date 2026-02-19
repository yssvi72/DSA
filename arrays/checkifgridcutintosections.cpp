class Solution {
public:
    // 0 -> end
    // 1 -> start
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        // horizontal
        vector<pair<int, int>> hor;
        for(int i=0; i<rectangles.size(); i++) {
            hor.push_back({rectangles[i][0], 1});
            hor.push_back({rectangles[i][2], 0});
        }
        sort(hor.begin(), hor.end());

        // vertical
        vector<pair<int, int>> vert;
        for(int i=0; i<rectangles.size(); i++) {
            vert.push_back({rectangles[i][1], 1});
            vert.push_back({rectangles[i][3], 0});
        }
        sort(vert.begin(), vert.end());

        // sliding line -> vertical line
        int overlap = 0;
        int line = 0;
        for(int i=0; i<hor.size(); i++) {
            if(hor[i].second == 1) {
                overlap++;
            }
            else {
                overlap--;
            }

            if(overlap == 0) {
                line++;
            }
        }
        if(line >= 3) return true;

        // sliding line -> horizontal line
        overlap = 0;
        line = 0;
        for(int i=0; i<vert.size(); i++) {
            if(vert[i].second == 1) {
                overlap++;
            }
            else {
                overlap--;
            }

            if(overlap == 0) {
                line++;
            }
        }
        if(line >= 3) return true;

        return false;
    }
};
