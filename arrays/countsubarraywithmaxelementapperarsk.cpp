class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        ll maxi=*max_element(nums.begin(),nums.end());
        ll n=nums.size();
        // vector<ll>pf(n);
        // pf[0]=((nums[0]==maxi)?1:0);
        // for(ll i=1;i<n;i++)pf[i]=pf[i-1]+((nums[i]==maxi)?1:0);
        ll l=0,r=0;
        ll count=0;
        ll ans=0;
        while(r<n){
            count=count+((nums[r]==maxi)?1:0);
            while(l<n && count>=k){
                //if l to r is valid then l to r+1,l to r+2.. l to n-1 is also valid
                ans=ans+(n-r);
                count=count-((nums[l]==maxi)?1:0);
                l++;
            }
            r++;
        }
        return ans;
    }
};
