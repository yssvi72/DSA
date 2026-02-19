class Solution {
public:
    bool rotateString(string s, string goal) {
     if(s.size() != goal.size())
            return false;
        if(s == goal)      //for empty strings
            return true;
        
        int len = goal.size();
        while(len--)
        {
            if(s == goal)
                return true;
            s = s.substr(1) + s[0];     // one shift on A
        }
        return false;   
    }
};
