class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int i=0;
        int index=0;
        int num_operation=0;
        while(i<nums.size())
        {
            int iteration=i+3;
            while(i<nums.size() && i<iteration)
            {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
            {
              num_operation++;
             index+=3;
             i=index;
             mp.clear();
             break;
            }
            i++;
            }
        }
        return num_operation;
    }
};
