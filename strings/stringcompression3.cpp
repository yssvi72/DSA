class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int n = word.size();

        int i=1;
        int count = 1;
        while(i<n) {
            while(i<n && word[i] == word[i-1]) {
                count ++;
                i++;
            }
            
            while(count>9) {
                res += to_string(9) + word[i-1];
                count -= 9;
            }

            res += to_string(count) + word[i-1];
            i++;
            count = 1;
        }

        if(i==n)
            res += to_string(count) + word[n-1];

        return res;
    }
    /*
    aaaaaaaaaaaaaabb

    count=14;
    i=1
    */
};
