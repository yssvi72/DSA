class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
          vector<vector<int>> ans;
       int s=original.size();
       if(s != m*n) { return ans;}
       vector<int> add;
       for( int i=0;i<s;i++){
          add.push_back(original[i]);
          if(add.size()==n){
            ans.push_back(add);
            add.clear();
          }
       } return ans;
    }
};
