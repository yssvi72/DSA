class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());

        int val = 0;

        for(int i = 0;i<=n;i++){
            val^=i;
        }

        for(int num : nums){
            val^=num;
        }

        int set_bit_pos = 0;

        while((val&(1<<set_bit_pos)) == 0){
            set_bit_pos++;
        }

        int g1 = 0;
        int g2 = 0;

        for(int num:nums){
            if(num & (1<<set_bit_pos)){
                g1^=num;
            }else{
                g2^=num;
            }
        }

        for(int i = 0;i<=n;i++){
            if(i &(1<<set_bit_pos)){
                g1^=i;
            }else{
                g2^=i;
            }
        }
        return {g1,g2};
    }
};
