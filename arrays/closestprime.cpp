class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> isPrime(right+1, 1);
        isPrime[0]=isPrime[1]=0;
        for(int i=2;i*i<=right;i++) {
            if(isPrime[i]==1) {
                for(int j=i*i;j<=right;j+=i)
                    isPrime[j]=0;
            }
        }
        int prev = -1, diff=INT_MAX, a,b;
        for(int i=left;i<=right;i++) {
            if(isPrime[i]) {
                if(prev!=-1 && diff>(i-prev))
                {
                    diff=i-prev;
                    a=prev;
                    b=i;
                }
                prev=i;
            }
        }
        if(diff==INT_MAX)
            return {-1, -1};
        return {a,b};
    }
};
