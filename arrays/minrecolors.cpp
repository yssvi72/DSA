class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=k,op=0,i=0,j=0;
        while(j<blocks.size()&&j<k){
            if(blocks[j]=='W')
            op++;
            j++;
        }
        ans=min(ans,op);
        while(j<blocks.size()){
            if(blocks[i]=='W'){
                op--;
                if(blocks[j]=='W')
                op++;
            }
            else{
                if(blocks[j]=='W')
                    op++;
            }
            i++;
            j++;
            ans=min(ans,op);
        }
        return ans;
    }
   
};
     //brute force appprach;
    //  int ans=k;
    //     for(int i=0;i<blocks.size();i++){
    //          int  count=0,op=0;
    //          for(int j=i;j<blocks.size()&&j<i+k;j++){
    //             if(blocks[j]=='W'){
    //                 op++;
    //                 count++;
    //             }
    //             else{
    //                 count++;
    //             }
    //          }
    //          if(count>=k)
    //          ans=min(op,ans);
    //     }
    //     return ans;  
    // }
