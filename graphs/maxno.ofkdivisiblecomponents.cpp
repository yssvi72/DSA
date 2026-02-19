class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        map<int ,vector<int>> adj;
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vec(n,0);
        stack<int>stk;
        int count=0;
        int sum=0;
        stk.push(0);
        vec[0]=1;
        
        while(!stk.empty()){
            int x=stk.top();

            int flag=0;
            for(int i=0; i<adj[x].size(); i++){

                if(vec[adj[x][i]]==0){
                    stk.push(adj[x][i]);
                    vec[adj[x][i]]=1;
                    flag=1;
                    
                    break;
                }
            }
            
            if(flag==0){
                if(values[x]%k==0){
                    count++;
                    stk.pop();  
                }else{

                    sum=(sum+values[x]%k)%k;
                    stk.pop();
                    if(!stk.empty()){
                        
                        values[stk.top()]+= values[x]%k;
                    }
                }
                
            }
        }
        return count;
    }
};
