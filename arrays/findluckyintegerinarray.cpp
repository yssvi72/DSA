class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        // First count the frequency
        for(auto num : arr){
            freq[num]++;
        }
        int max_num = 0;
        for(auto i = freq.begin(); i != freq.end(); i++){
            if(i->first == i->second){
                max_num = max(max_num, i->second);
            }
        }
        if(max_num == 0){
            return  -1;
        }else{
            return max_num;
        }
    }
};
