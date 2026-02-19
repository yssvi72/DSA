class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int ans = 0;
        int i = 0;
        int j = 0;
        while(i < n){
            while(j < n && (fruits[i] > baskets[j] || used[j])){
                j++;
            }
            if(j < n) used[j] = true;
            i++;
            j = 0;
        }
        for(int ns : used) if(!ns) ans++;
        return ans;
    }
};
