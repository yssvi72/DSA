class Solution {
    int mxSum(vector<int> &a){
        int n=a.size();
        int ans=INT_MIN;
        int curr=0;
        
        for(int i=0; i<n; i++){
            int temp=curr+a[i];
            
            if(temp<=a[i]){
                curr=a[i];
            }
            else curr+=a[i];
            
            ans=max(ans, curr);
        }
        
        ans=max(ans, curr);
        
        return ans;
    }

    int mnSum(vector<int> &a){
        int n=a.size();
        int ans=INT_MAX;
        int curr=0;
        
        for(int i=0; i<n; i++){
            int temp=curr+a[i];
            
            if(temp>=a[i]){
                curr=a[i];
            }
            else curr+=a[i];
            
            ans=min(ans, curr);
        }
        
        ans=min(ans, curr);
        
        return ans;
    }
public:
    int maxAbsoluteSum(vector<int>& a) {
        return max(abs(mxSum(a)), abs(mnSum(a)));
    }
};
