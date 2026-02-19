class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m=banned.size();
        int count=0;
        int inc=0;
        vector<int>v(10001,0);
        for(int i=0;i<m;i++){
            v[banned[i]]=1;
        }
            for(int j=1;j<=n;j++){
                if(v[j]==1){
                    continue;
                }
                count+=j;
                if(count>maxSum){
                    break;
                }
                inc++;
            }
        return inc;
    }
};
