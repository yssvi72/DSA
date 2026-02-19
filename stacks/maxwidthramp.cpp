class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;//store indexes of elements

        st.push(n-1);
        for(int i = n-2;i>=0;i--){// indexes of next greater
            if(nums[i] > nums[st.top()]){
                st.push(i);
            }
        }

        int temp = st.top(),ans = 0;

        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){// while top element is greater checking for next possibility 
                temp = st.top();
                st.pop();
            }

            ans = max(ans,temp - i);
        }

        return ans;
    }
};
