int MOD=1e9+7;
class Solution {
public:
int findPower(long long a, long long b){
    if(b==0){
        return 1;
    }
    long long half=findPower(a,b/2);
    int result=(half*half)%MOD;
    if(b%2==1){
        result=(result*a)%MOD;
    }
    return result;
}
long long ncr(int n, int r, vector<long long>& fact, vector<long long>& fermatFact){
    return fact[n] * fermatFact[n-r] %MOD * fermatFact[r] % MOD;
}
    int countGoodArrays(int n, int m, int k) {
        vector<long long>fact(n+1,1);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=n;i++){
            fact[i]=(fact[i-1]*i)%MOD;
        }
        vector<long long>fermatFact(n+1,1);
        for(int i=0;i<=n;i++){
            fermatFact[i]=findPower(fact[i],MOD-2);
        }
        long long result=ncr(n-1,k,fact,fermatFact);
        result = (result*m)%MOD;
        result = (result*findPower(m-1,n-k-1))%MOD;
        return result;
    }
};
