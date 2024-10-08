class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        vector <char> stk;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                stk.push_back(s[i]);
            }
            else{
                if(!stk.empty()){
                    stk.pop_back();
                }else{
                    count = count + 1;
                }
            }
        }
        
        return (count+1)/2;
    }
};
