class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size(), m=part.size();
        string str = s;
        while(s.size() >= m){
            n = s.size();
            for(int i=0;i<=n-m;i++){
                if(s.substr(i,m) == part){
                    str = s.substr(0,i) + s.substr(i+m);
                    break;
                }
            }
            if(str == s){
                return str;
            }
            s = str;
        }
        return s;
    }
};
