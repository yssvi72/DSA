class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        map<int,vector<int>>mpp;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>ans;
        bool flip = true;   
        for(auto &x: mpp){
            if(flip){
                reverse(x.second.begin(), x.second.end());
            }
            for(auto &num : x.second) ans.push_back(num);
            flip = !flip;
        }
        return ans;
    }
};
