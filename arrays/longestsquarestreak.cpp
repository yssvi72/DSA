class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxans = -1;
        sort(nums.begin(), nums.end());
        int size = nums.size() -1 ;
        map<int,int>mp;
        for (int i = 0; i <= size; i++) {
            int element = nums[i];
            long long  square = (long long )element * (long long)element;
            if (binary_search(nums.begin(), nums.end(), square)) {
                mp[element] = square; // maping the number and there square 
            }
        }

        for (int i = 0;i<=size;i++){
            int element = nums[i];
            int temp = 1;
            while(mp.find(element) != mp.end()){
                temp++;
                element = mp[element];
            }
            maxans = max(temp,maxans);
        }

        return maxans < 2 ? -1 : maxans;
        
    }
};
