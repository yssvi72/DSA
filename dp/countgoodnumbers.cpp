#define ll long long
#define mod 1000000007
#define ll long long
#define mod 1000000007
class Solution {
public:
    int primes[4] = {2, 3, 5, 7}; 
    int even[5] = {0, 2, 4, 6, 8};
    int cnt = 0;
    string x = "";

    ll dp[100001][2]; 

    ll power(ll a, ll b) {
        ll res = 1;
        while(b > 0) {
            if(b % 2) res = (res * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }

    ll mem(ll i , ll n , bool flag ){

        if(i==n){
            return 1 ; 
        }

        if(dp[i][flag]!=-1) return dp[i][flag] ;  
        int ch= 0 ; 
        if(flag){
            ch = 5 ; 
        }
        else{
            ch = 4 ; 
        }
        ll ans =0  ;
        for(int j = 0 ; j< ch ;j++){
            ans = (ans + mem(i+1, n, !flag))% mod;
        }

        return dp[i][flag] = ans ;




    }

    // void rec(ll n, bool flag) {
    //     if (x.length() == n) {
    //         cnt++;
    //         return;
    //     }

    //     if (flag) {
    //         for (int i = 0; i < 5; i++) {
    //             x += (even[i] + '0');
    //             rec(n, !flag);
    //             x.pop_back();
    //         }
    //     } else {
    //         for (int i = 0; i < 4; i++) {
    //             x += (primes[i] + '0');
    //             rec(n, !flag);
    //             x.pop_back();
    //         }
    //     }
    // }

    int countGoodNumbers(long long n) {

        
        if (n > 100000) {
            ll evenCount = (n + 1) / 2;
            ll primeCount = n / 2;
            return (power(5, evenCount) * power(4, primeCount)) % mod;
        }

        memset(dp,-1,sizeof(dp));
    
        return mem(0 , n, true) ;
    }
};
