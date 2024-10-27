class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(matrix[i][j] != 0){

                    int u=0,l=0,d=0;
                    if(j-1 >= 0){
                        l=matrix[i][j-1];
                    }

                    if(i-1 >= 0){
                        u=matrix[i-1][j];
                    }

                    if(i-1 >= 0 && j-1 >= 0){
                        d=matrix[i-1][j-1];
                    }

                    if(u != 0 && l != 0 && d != 0){
                        int val = min(u,min(l,d));
                        matrix[i][j] = val+1;
                    }

                    ans += matrix[i][j];
                }
            }
        }

        return ans;
    }
};
