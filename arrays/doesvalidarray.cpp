class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0;
        for(auto val :  derived){
            ans = ans ^ val;//val is o[i] xor o[i+1] where o is original
        }
        if(ans==0) return true;
        else{
            return false;
        }

    
        
    }
};
