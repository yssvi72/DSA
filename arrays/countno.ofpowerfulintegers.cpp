class Solution {
private:
long long calc(int l,int n){
    long long res = 1;
    while(n--){
        res *= l+1;
    }
    return res;
}
private:
    long long helper(long long num,int limit,string s){
        string st = to_string(num);
        int n = st.size();
        int m = s.size();
        long long ans = 0;
        int i=0;
        for(i=0;i<n-m;i++){
            int digit = st[i]-'0';
            ans += (long long)min(digit,limit+1)*calc(limit,n-m-i-1);
            if(limit<digit) break;
        }
        // cout << i << " "<<ans <<endl;
        if(i != n-m) return ans;
        bool flag = true;
        for(int j=n-m;j<n;j++){
            if(s[j-n+m]<st[j]) break;
            if(s[j-n+m] > st[j]){
                flag = false;
                break;
            }
        }
        return flag ? ans+1 : ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

        long long left = helper(finish,limit,s);
        long long right = helper(start-1,limit,s);
        // cout << left << " "<<right;
        return left-right;
    }
};
