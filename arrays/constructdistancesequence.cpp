class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int totalLength = 2*n - 1;
        vector<int>arr(totalLength,0);
        vector<bool>done(n+1,false);
        recur(arr,done,0,n);
        return arr;
    }
    bool recur(vector<int>& arr, vector<bool>&done, int idx, int n) {
        if(idx == 2*n-1) {
            return true;
        }
        if(arr[idx]!= 0) {
            return recur(arr,done,idx+1,n);
        } else {
            for(int i = n; i > 0; i--) {
                if(!done[i] && (i == 1 || (i + idx < (2*n)-1) && arr[i+idx]== 0)) {
                    arr[idx] = i;
                    if(i > 1) {
                        arr[idx+i] = i;
                    }
                    done[i] = true;
                    if (recur(arr,done,idx+1,n))
                        return true;
                    arr[idx] = 0;
                    if(i > 1) {
                        arr[idx+i] = 0;
                    }
                    done[i] = false;
                }
            }
            return false;
        }

    }
};
