class Solution {
public:
    long long maxHeap(vector<int>&gifts, int k)
    {
        priority_queue<int>pq;

        for(auto i : gifts)
        {
            pq.push(i);
        }

        for(int i=0;i<k;i++)
        {
            int maxPile = pq.top();
            pq.pop();
            pq.push(sqrt(maxPile));
        }


        long long remainGifts = 0;
        
        while(!pq.empty())
        {
            remainGifts+=pq.top();
            pq.pop();
        }

        return remainGifts;
    }

    long long sorting(vector<int>&gifts, int k)
    {
        while(k)
        {
            // [25,64,9,4,100]
            sort(gifts.begin(),gifts.end(),[](int a, int b){ return a>b; });
            // [100,64,25,9,4]
            int maxPile = gifts[0];
            gifts.erase(gifts.begin());
            // [64,25,9,4]
            gifts.push_back(sqrt(maxPile));
            // [64,25,9,4,10]
            k--;
        }
        
        long long remainGifts = 0;

        for(auto i : gifts)
        {
            remainGifts+=i;
        }

        return remainGifts;
    }


    long long pickGifts(vector<int>& gifts, int k) {
        // int ans = sorting(gifts,k);
        long long int ans = maxHeap(gifts,k);

        return ans;
    }
};
