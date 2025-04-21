class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        
        long rolling_sum = 0;
        long _max = 0, _min = 0;

        for(int d : differences) {
            rolling_sum += d;
            _max = max(_max, rolling_sum);
            _min = min(_min, rolling_sum);
        }

        long range = upper - lower - (_max - _min);

        return (range < 0) ? 0 : range + 1;
    }
};
