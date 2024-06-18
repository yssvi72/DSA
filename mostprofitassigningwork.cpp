class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int res = 0, j = 0, best = 0;
        vector<pair<int, int>> temp;
        for(int i = 0; i < worker.size(); ++i) {
            temp.push_back({difficulty[i], profit[i]});
        }

        sort(begin(temp), end(temp));
        sort(begin(worker), end(worker));
        for(int work : worker) {
            while(work >= temp[j].first && j < worker.size()) {
                best = max(best, temp[j++].second);
            }
            
            res += best;
        }

        return res;
    }
};
