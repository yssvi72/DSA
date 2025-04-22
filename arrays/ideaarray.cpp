const int mod = 1e9+7;
long long power(long long x, unsigned int y) { 
    long long res = 1;     
    while (y > 0) { 
        if (y & 1) res = (x*res)%mod; 
        y = y>>1; 
        x = (x*x)%mod; 
    } 
    return res; 
}
int distComb[10001];
class Solution {
    int n=0, maxValue=0;
    void initDistComb(int i, int last){
        if(i>n||last>maxValue) return;
        for(int num=2*last;num<=maxValue;num+=last) {
            distComb[i]++; initDistComb(i+1,num);
        }
    }
public:
    int idealArrays(int n, int maxValue) {
        this->n=n; this->maxValue=maxValue;
        memset(distComb,0,(n+1)*sizeof(int));
        distComb[1]=maxValue;
        for(int num=1;num<=maxValue;num++) initDistComb(2,num);
        long n1Ci1 = 1; long res=0;
        for(int i=1;i<=n;i++) {
            res+=(long)distComb[i]*n1Ci1;
            if(res>mod) res%=mod;
            n1Ci1 = n1Ci1*((n-i)*power(i,mod-2)%mod)%mod;
        }
        return res;
    }
};
