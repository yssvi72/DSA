class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int pl = 1 , sl = 1;
        for(int i = 0; i < arr.size()-1 ; i++)
        {
            if(arr[i]<=arr[i+1]) pl++;
            else break;
        }
        for(int i = arr.size() -1 ; i>=1 ; i--)
        {
            if(arr[i-1]<=arr[i]) sl++;
            else break;
        }
        cout << pl <<" "<< sl<< endl;
        // if(sl==1 && pl == 1) return n-1 ;
        if(pl==n) return 0;
        int l = 0; int r = n - sl; int length = max(pl ,sl);
        while(l < pl && r < n )
        {
            if(arr[l]<=arr[r]) 
            {
                length = max(length , l+1+n - r);
                l++;
            }
            else
            {
                r++;
            }
        }
        return n - length;
    }
};
