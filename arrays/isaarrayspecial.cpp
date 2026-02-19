class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        int n= nums.size(); 
        if( n <=1 )return true ; 

        for(int i = 0 ; i < n -1 ; i++ ){

            //xor of same element zero and 
            // nums[i] & 1 ( is 1 when they are odd )
            //num[i] & 1 ( is 0 when they are even )
            // so  0 ^  0 is zero 
            //so 1 ^ 1 is zero 
            // 1 ^ 0 or 0 ^ 1 is 1 ( differnet parity )
            if(  ( ( nums[i] &1 ) ^ ( nums[i+1] & 1 ))==0)return false ; 
        }
        return true ; 
    }
};
