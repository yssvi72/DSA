class Solution {
public:
    int punishmentNumber(int n) 
    {
        // Precomputed list of valid punishment numbers
        int punishmants[] = {1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657, 675, 703, 756, 792, 909, 918, 945, 964, 990, 991, 999, 1000};
        int ans = 0;
        // Iterate through the list and sum the squares of valid numbers <= n
        for (int i : punishmants) 
        {
            if (i <= n)
                ans += (i * i); // Add the square of the number
            else
                break; // Stop once we exceed n
        }
        return ans;  
    }
};
