class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> code2=code;
        int n=code.size();
        vector<int> ans;
        if(k==0){
            return vector<int>(n,0);
        }
        for(int i=0;i<n;i++){
            code2.push_back(code[i]);
        }

        if(k>0){
            for(int i=0;i<n;i++){
                int sum=0;
                int j=i+1;
                int cnt=0;
                while(cnt!=k){
                    sum+=code2[j];
                    j++;cnt++;
                }
                ans.push_back(sum);
            }
        }else{
            for(int i=n;i<2*n;i++){
                int sum=0;
                int j=i-1;
                int cnt=0;
                while(cnt!=abs(k)){
                    sum+=code2[j];
                    j--;cnt++;
                }
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
