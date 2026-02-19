class Solution {
public:
    typedef pair<int, char>  P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq; //max-heap

        if(a > 0){
            pq.push({a, 'a'});
        }
        if(b > 0){
            pq.push({b, 'b'});
        }
        if(c > 0){
            pq.push({c, 'c'});
        }

        string ans = "";

        while(!pq.empty()){
            int currCount = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            if(ans.length() >=2 && ans[ans.length()-1] == currChar && ans[ans.length()-2] == currChar){
                //can't use currChar then check for next large;
                if(pq.empty()){
                    break;
                }
                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                ans.push_back(nextChar);
                nextCount--;
                if(nextCount > 0){
                    pq.push({nextCount, nextChar});
                }
            }
            else{
                currCount--;
                ans.push_back(currChar);
            }

            if(currCount > 0){
                pq.push({currCount, currChar});
            }
        }
        return ans;
    }
};
