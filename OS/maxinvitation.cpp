class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int> indegree(n,0);
        vector<bool>visited(n,false);
        vector<int> longestChain(n,0);
        for(int i=0;i<n;++i)
        {
            indegree[favorite[i]]++;
        }
        queue<int> q;
        for(int i=0;i<n;++i)
        {
          if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            visited[node]=true;
            int next=favorite[node];
            longestChain[next]=max(longestChain[next],longestChain[node]+1);
            if(--indegree[next]==0) q.push(next);
        }
        int maxCycleLength=0;
        int chainSum=0;
        for(int i=0;i<n;++i)
        {
            if(!visited[i])
            {
                int cycleLength=0,node=i;
                while(!visited[node])
                {
                    visited[node]=true;
                    node=favorite[node];
                    cycleLength++;
                }
                if(cycleLength==2)
                {
                    chainSum+=cycleLength+longestChain[i]+longestChain[favorite[i]];
                }
                else
                {
                    maxCycleLength=max(maxCycleLength,cycleLength);
                }
            }
        }

     return max(maxCycleLength,chainSum);
        
    }
};
