class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,list<string>>adj;
        unordered_map<string,int>indegree;
        unordered_map<string,bool>isrecipe;
        for(int i=0;i<recipes.size();i++){
            string recipe = recipes[i];
            isrecipe[recipe] = true;
            for(auto ingredient : ingredients[i]){
                adj[ingredient].push_back(recipe);
                indegree[recipe]++;
            }
        }
        queue<string>q;
        vector<string>ans;
        for(auto s:supplies){
            indegree[s]=0;
            q.push(s);
        }
        while(!q.empty()){
            auto s = q.front();
            q.pop();
            for(auto neigh:adj[s]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                   q.push(neigh);
                   if(isrecipe[neigh]) ans.push_back(neigh); 
                }
            }
        }
        return ans;
    }
};
