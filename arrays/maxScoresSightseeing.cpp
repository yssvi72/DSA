class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = -1;
        int lastMax = values[0] + 0;
        for(int i = 1;i < n;i++){
            maxi = max(maxi,lastMax + (values[i] - i));
            if((values[i] + i) > lastMax){
                lastMax = values[i] + i;
            }
        }
        return maxi;
    }
};
