class Solution {
public: 
    vector<int> ans;
    void dfs(int num,int n){
        if(num>n)return ;
        ans.push_back(num);
        dfs(num*10,n);
        if(ans.size()<n&&(num+1)%10!=0)dfs(num+1,n);
        return ;


    }
    vector<int> lexicalOrder(int n) {
        dfs(1,n);
        return ans;


    }
};
