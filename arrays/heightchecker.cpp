class Solution {
public:
    int heightChecker(vector<int>& heights) {
         if (heights.size()<2)
            return 0;
        
        // The basic idea is to utilize the information regarding the [1,100] interval
        vector<int> map(101,0);
        
        // Record all the values in original array and count its occurences
        for (int h:heights)
            map[h]++;
        
        int res = 0;
        
        // h pointer points to the values in a sorted array
        int h_ptr = 1;
        
        for (int h:heights)
        {
            // Sorted value increases if no such value exists in original array
            while (map[h_ptr]==0)
                h_ptr++;
            
            // If h does not equal h_ptr, it means h is not at right position 
            if (h != h_ptr)
                res++;
            
            // If there are multiple occurences for a single value, keep h_ptr unchanged
            // untill passing all the positions corresponding to this specific value
            map[h_ptr]--;
        }
        
        return res;
    }
};
