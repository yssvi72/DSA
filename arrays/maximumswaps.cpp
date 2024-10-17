class Solution {
public:
    int maximumSwap(int x) {
        string s = to_string(x);
        int mx=-1,mxi=-1;
        int ans = x;
        for(int i=s.size()-1;i>=0;i--){
            int d = s[i];
            if(d > mx){
                mx=d;
                mxi=i;
            }
            else{
                swap(s[i],s[mxi]);
                ans = max(ans,stoi(s));
                swap(s[i],s[mxi]);
            }
        }
        return ans;
    }
};
