class Solution {
public:
    void bfs(unordered_map<char,vector<pair<char,int>>>&graph,char source,vector<vector<int>>&distances){
//Normal BFS shortest path code
//Saving calculated distance in distances array

        queue<pair<int,int>>q;
        q.push({source,0});
        while(!q.empty()){
            int node = q.front().first;
            int distance=q.front().second;
            q.pop();
            for(auto child:graph[node]){
                if(distances[source-'a'][child.first-'a']>distance+child.second){

                    distances[source-'a'][child.first-'a']=distance+child.second;
                    q.push({child.first,distance+child.second});
                }
            }
            
        }
        return;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        unordered_map<char,vector<pair<char,int>>>graph;

//Initialzing the graph in the node schema : {parent,{child,cost}}
        for(int i=0;i<original.size();i++){
            graph[original[i]].push_back({changed[i],cost[i]});
        }

        //Distance array required will only need 26*26 space.
        vector<vector<int>>distances(26,vector<int>(26,INT_MAX));

        //Running BFS from every node of original string.
        for(auto it:original)
        bfs(graph,it,distances);
        
        long long ans=0;
        for(int i=0;i<source.size();i++){

//No need to add anything to answer if source and target are same
            if(source[i]==target[i])continue;

//If Distance is infinite, the target is not achievable and hence return -1
            if(distances[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;

//Otherwise add the corresponding value in the distances array
            else ans+=distances[source[i]-'a'][target[i]-'a'];
        }
        
        return ans;
    }
};
