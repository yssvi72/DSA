class Solution {
public:
    long long putMarbles(vector<int>& arr, int k) {
        
        int n = arr.size();
        priority_queue<int> maxPQ;
        priority_queue<int,vector<int>,greater<int>> minPQ;

        for(int i =0;i<n-1;i++){
            maxPQ.push(arr[i]+arr[i+1]);
            minPQ.push(arr[i]+arr[i+1]);
        }

        long long maxi = 0;
        long long mini = 0;
        int index = k-1;
        while(index){
            maxi+=maxPQ.top();
            maxPQ.pop();
            index--;
        }

        index = k-1;
        while(index){
            mini+=minPQ.top();
            minPQ.pop();
            index--;
        }

        return maxi-mini;
    }
};
