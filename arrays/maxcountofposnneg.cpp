class Solution {
public:
    int maximumCount(vector<int>& nums) {
      
        int i=0;
        int n=nums.size();
        int countn=0;
        int countp=0;
  
        int j=n-1;
        while(i<=j)
        {
            
            if(nums[i]==0&&nums[j]==0)
            {
                break;
            }
           
            if(nums[i]<0)
            {
                countn++;
                i++;
            }
             if(nums[j]>0)
            {
                countp++;
                j--;

            }
            
        }

        return max(countn,countp);
    }
};
