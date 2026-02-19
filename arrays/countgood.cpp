class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int end = 0, start = 0;
        long long ans = 0;
        long long pair = 0;
        unordered_map<int,int>map;
        while(end < n ){
            map[nums[end]]++;
            if(map.find(nums[end]) != map.end()){
                pair += map[nums[end]]-1;
            }
            while(start <= end and pair >= k){
                ans += (long long)n - (long long)end;
                --map[nums[start]];
                pair -= map[nums[start]];
                if(map[nums[start]] == 0)map.erase(nums[start]);
                start++;
            }
            
            end++;
        }
        return ans;
    }
};
