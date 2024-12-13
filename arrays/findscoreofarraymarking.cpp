class Solution {
public:
    long long findScore(vector<int>& nums) 
    {
        long long score = 0;
        unordered_map<int,int>m;

        for(int i = 0 ; i < nums.size() ; i++)
        m[i]++;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >p;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            p.push({nums[i] , i});
        }

        while(p.size())
        {
            int ele = p.top().first;
            int ind = p.top().second;

            cout<<ind<<" ";
            p.pop();

            if( m[ind] == 0 )
            continue;
            
            else
            {
                m[ind] = 0;
                
                if(ind - 1 >= 0)
                m[ind-1] = 0;

                if(ind+1 < nums.size())
                m[ind+1] = 0;

                score += ele;

            }

        }

        return score;
        
    }
};
