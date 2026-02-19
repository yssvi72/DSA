class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        long long sum = 0;
        priority_queue<int> pq;
        for(int i : nums){
            pq.push(i);
        }

        while(!pq.empty() && k){
            int curr = pq.top();
            pq.pop();

            sum += curr;
            pq.push(ceil(curr / 3.0));
            k--;
        }
        return sum;
    }
};
