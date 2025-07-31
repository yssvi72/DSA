class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, cur, next;
        cur.insert(0);
        for(int i=arr.size()-1; i>=0; i--){
            next.insert(0);
            for(auto e : cur){
                int m = e | arr[i];
                ans.insert(m);
                next.insert(m); 
            }
            cur = next; next.clear();
        }
        return ans.size();
    }
};
