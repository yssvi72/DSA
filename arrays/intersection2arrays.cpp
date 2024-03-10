class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         int H[1000] = {0};
        vector<int> ans;
        for(int i =0; i<nums1.size(); i++){
            if(H[nums1[i]] == 0) H[nums1[i]]++;
        }
        for(int i =0; i<nums2.size(); i++){
            if(H[nums2[i]] != 0) {
                ans.push_back(nums2[i]);
                H[nums2[i]]--;
            }
        }
        return ans;
    }
};
