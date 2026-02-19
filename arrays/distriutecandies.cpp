
class Solution 
{
public:
    long long count_ways(int n) 
    {
        if (n < 0) return 0;
        return 1LL * (n + 2) * (n + 1) / 2;
    }
    long long distributeCandies(int n, int limit) 
    {
        int limit_Plus_One = limit + 1;
        long one_Child_Exceeds_Limit = count_ways(n - limit_Plus_One);
        long two_Children_Exceed_Limit = count_ways(n - 2 * limit_Plus_One);
        long three_Children_Exceed_Limit = count_ways(n - 3 * limit_Plus_One);

        return count_ways(n)
             - 3 * one_Child_Exceeds_Limit
             + 3 * two_Children_Exceed_Limit
             -     three_Children_Exceed_Limit;
    }
};
