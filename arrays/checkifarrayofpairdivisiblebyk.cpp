class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder(k, 0);
        for(int i = 0; i<arr.size(); i++){
            int r = ((arr[i]%k)+k)%k;
            remainder[r]++;
        }
        if(remainder[0]%2 != 0){
            return false;
        }
        for(int i = 1; i<= k/2; i++){
            if(remainder[i] != remainder[k-i]){
                return false;
            }
        }
     return true;
    }
};
