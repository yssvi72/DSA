class Solution {
public:
    int maxScore(string s) {
        int total=0;
        for(auto it:s) {
            if(it=='1') total++;
        }

        int sum0=0;
        int maxi=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='0') {
                sum0+=1; 
            }else{
                total-=1;
            }
            if(i!=s.size()-1) maxi=max(maxi,sum0+total);
        }
        return maxi;
    }
};
