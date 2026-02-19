class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>antrip;
        unordered_map<int,bool>guava;
        int m=edges.size(),s=((n-1)*(n))/2;
        for(int i=0;i<m;i++){
            if(!guava[edges[i][1]])s-=edges[i][1];
            guava[edges[i][1]]=true;
            antrip[edges[i][0]].push_back(edges[i][1]);
        }
        if(guava.size()!=n-1)return -1;
        return s;
    }
};
