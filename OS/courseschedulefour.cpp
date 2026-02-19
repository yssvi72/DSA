class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>isreachable(numCourses , vector<int>(numCourses,0));
        vector<vector<int>>edges(numCourses);
        
        for(int i = 0 ; i<prerequisites.size() ; i++){
            edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<vector<int>>visited(numCourses,vector<int>(numCourses,0));
        queue<int>qq;
        for(int i = 0 ; i<numCourses ; i++){            
            for(auto it:edges[i]){
                qq.push(it);
                isreachable[i][it]=1;
                visited[i][it]=1;
            }
            while(!qq.empty()){
                int top = qq.front();
                qq.pop();
                for(auto it:edges[top]){
                    if(visited[i][it]==0)qq.push(it);
                    isreachable[i][it]=1;
                    visited[i][it]=1;
                }
            }
        }
        vector<bool>ans;
        for(int i = 0 ; i<queries.size() ; i++){
            ans.push_back(isreachable[queries[i][0]][queries[i][1]]);
        }
        return ans;
    }
};
