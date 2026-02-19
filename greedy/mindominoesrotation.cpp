class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> arr1(7,0),arr2(7,0);
        int ans = 10000000;
        int n = tops.size();

        for(int i = 1;i <= 6;i++){
            for(int j = 0;j < n;j++){
                if((tops[j] == i) || (bottoms[j] == i)){
                    if(tops[j] == i) arr1[i]++;
                    if(bottoms[j] == i) arr2[i]++;
                }
                else{
                    arr1[i] = -1;
                    break;
                }
            }
        }

        for(int i = 1;i <= 6;i++){
            if(arr1[i] != -1){
                int w = min(arr1[i],arr2[i]) - (arr1[i] + arr2[i] - n);
                if(w < ans) ans = w;
            }
        }

        if(ans == 10000000) ans = -1;

        return ans;
    }
};
