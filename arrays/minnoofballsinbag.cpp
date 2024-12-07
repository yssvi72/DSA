class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end()), mid = 0, mini = right, len = nums.size();

        while(left <= right){
            mid = (right + left)/2;

            int ops = 0;
            
            for(int i = 0; i < len; i++){
                ops += (nums[i] / mid);
                if(nums[i] % mid == 0) ops--;
                if(ops > maxOperations) break;
            }

            if (ops <= maxOperations){
                right = mid-1;
                mini = min(mini, mid);
            }else left = mid+1;
        }

        return mini;
    }
};
