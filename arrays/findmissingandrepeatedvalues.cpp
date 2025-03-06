class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> freq;
        vector<int> res(2);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 freq[grid[i][j]]++;
            }
        }
        for(int num=1;num<=(n*n);num++)
        {
            if(freq[num]==2)
            {
                res[0]=num;
            }
            else if(freq[num]==0)
            {
                res[1]=num;
            }
        }
        return res;
    }
};
