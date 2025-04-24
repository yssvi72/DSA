class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums)
{
    int n = nums.size(), ans=0, cnt=0, m=-1;
    unordered_set<int> s;
    for(auto u:nums) s.insert(u), m=max(m,u);    int k = s.size();
    int l=0, r=0;    vector<int> freq(m+1, 0);
    while(r<n)
    {
        if(!freq[nums[r]])  cnt++;
        freq[nums[r]]++;
        while(cnt==k)
        {
            ans += n-r; // count all subarrays from l to n-1
            freq[nums[l]]--;
            if(!freq[nums[l]])  cnt--;
            l++;
        }
        r++;
    }
    return ans;
}
};
