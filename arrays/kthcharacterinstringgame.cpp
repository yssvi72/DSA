class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        
        long long x = k;
        int op = 0;

        while(x){
            x /= 2;
            op++;//operations we need to perform on string to make it greater than k
        }

        long long int max = (long long)pow(2,op);//length of the string which is just greater than k

        int count = 0;

        while(max > 1){

            if(k>(max/2)){
                if(operations[op-1])count++; //operations[op-1] is the operation we did to make string of length max which was earlier max/2
                k -= (max/2);
            }
            op--;
            max /= 2;
        }

        count %= 26;

        return 'a' + count;
    }
};
