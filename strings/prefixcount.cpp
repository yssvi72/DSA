class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        bitset<100> bt;
        for(int j = 0; j < pref.size(); j++){
            for(int i = 0; i < n; i++){
                if(!bt[i] && (j >= words[i].size() || words[i][j] != pref[j])){
                    bt.set(i);
                }
            }
        }
        return n-bt.count();
    }
};
