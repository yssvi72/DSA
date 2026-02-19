class DisjointSet{
    vector<int> rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }

    void Union(int u,int v){
        int upar_u=find(u);
        int upar_v=find(v);
        if(upar_u==upar_v) return;
        if(upar_u<upar_v) parent[upar_v]=upar_u;
        else if(upar_u>upar_v) parent[upar_u]=upar_v;
       
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet G(26);
        int m=s1.length();
        for(int i=0;i<m;i++){
            G.Union(s1[i]-'a',s2[i]-'a');
        }
        int n=baseStr.length();
        string s="";
        for(int i=0;i<n;i++){
            s+='a'+G.find(baseStr[i]-'a');
        }
        return s;
    }
};
