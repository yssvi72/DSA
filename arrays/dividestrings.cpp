class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();

        int count = 0;
        string temp = "";

        for(auto& ch : s){
            temp += ch;
            count += 1;

            if(count == k){
                res.push_back(temp);
                count = 0;
                temp = "";
            }
        }

        if(n % k != 0){
            temp += string(k - (n % k), fill);
            res.push_back(temp);
        }

        return res;
    }
};
