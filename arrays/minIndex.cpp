class Solution {
public:
    int minimumIndex(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        
        for(auto it: arr)
         mp[it]++;

        int maxi;
        for(auto it: mp)
         {
            if(it.second>n/2)
             maxi=it.first;
         }
        
        // cout<<maxi<<endl;
        vector<int> pre(n,0),post(n,0);
        
        if(arr[0]==maxi)
         pre[0]=1;
        if(arr[n-1]==maxi)
         post[n-1]=1;

        // cout<<pre[0]<<post[n-1]<<endl;
        


        for(int i=1;i<n;i++)
         {
            if(arr[i]==maxi)
             pre[i]=pre[i-1]+1;
            else 
             pre[i]=pre[i-1];
         }

        for(int i=n-2;i>=0;i--)
         {
            if(arr[i]==maxi)
             post[i]=post[i+1]+1;
            else
             post[i]=post[i+1];
         }
        
        
        // for(auto it: pre)
        //  {
        //     cout<<it<<" ";
        //  }
        // cout<<endl;
        // for(auto it: post)
        //  {
        //     cout<<it<<" ";
        //  }
        // cout<<endl;

       for(int i=0;i<n-1;i++)
        {
            int in=i+1;
            int ind=n-i-1;
            // cout<<in<<ind<<" "<<pre[i]<<post[i]<<endl;
            if(pre[i]>(in/2) && post[i+1]>(ind/2))
             return i;
        }
     return -1;
    }
};
