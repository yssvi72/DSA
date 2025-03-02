class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
        map<int,int>mp;
        for(int i=0;i<n1.size();i++){
            mp[n1[i][0]]+=n1[i][1]; 
        }
        for(int i=0;i<n2.size();i++){
            mp[n2[i][0]]+=n2[i][1]; 
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            ans.push_back({i.first,i.second});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
