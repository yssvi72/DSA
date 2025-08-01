//Pascal Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        for(int i=0;i<numRows;i++)
        {
            vector<int>rows(i+1,1);
            for(int j=1;j<i;j++)
            {
                rows[j]=pascal[i-1][j-1]+pascal[i-1][j];
            }
            pascal.push_back(rows);
        }
        return pascal;
    }
};
