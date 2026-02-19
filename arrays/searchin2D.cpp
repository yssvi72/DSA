    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  // number of rows
        int n = matrix[0].size();  // number of columns
        for(int i=0; i<m; i++){
            if(target >= matrix[i][0] && target <= matrix[i][n-1]){
                int low = 0, high = n-1, mid = (low+high)/2;
                while(low<=high){
                    if(target == matrix[i][mid] || target == matrix[i][low] || target == matrix[i][high]){
                        return true;
                    }
                    high--;
                    low++;
                }                
            }
        }
        return false;
