lass Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
      
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int reqTime = times[targetFriend][0];
        sort(times.begin(),times.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> visitersAndChairs;
        priority_queue<int,vector<int>,greater<int>> freeChairs;

        for(int i=0; i<times.size(); i++){
            freeChairs.push(i);
        }
        
        for(int i=0; i<times.size() ; i++){
            while(!visitersAndChairs.empty() && visitersAndChairs.top().first <= times[i][0]){
                freeChairs.push(visitersAndChairs.top().second);
                visitersAndChairs.pop();
            }
          
            int availableChair = freeChairs.top();
            freeChairs.pop();

            if(times[i][0] == reqTime) return availableChair;
            visitersAndChairs.push({times[i][1],availableChair});
            
        }
        
        return -1; 
    }
};
