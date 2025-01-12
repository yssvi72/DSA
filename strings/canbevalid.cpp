class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        int count = 0;
        if(n%2 != 0){
            return false;
        }
        for(int i=0 ; i<n ; i++){
            if(locked[i]=='0' || s[i]=='('){
                count++;
            }
            else{
                count--;
            }
            if(count<0){
                return false;
            }
        }
        count = 0 ;
        for(int i=n-1 ; i >= 0 ; i--){
            if(locked[i] == '0' || s[i] == ')'){
                count++;
            }
            else{
                count--;
            }
            if(count<0){
                return false;
            }
        }
        return true;
    }
};
