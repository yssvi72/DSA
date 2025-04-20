class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp; // Map to store frequency of each answer
        int result = 0;

        // Count how many times each answer appears
        for (int answer : answers) {
            mp[answer]++;
        }

        // Go through each unique answer
        for (auto a : mp) {
            if (a.first == 0) {
                // Rabbits that see no others of their color: count them as-is
                result += a.second;
            } else {
                int groupSize = a.first + 1; // Each group has (answer + 1) rabbits
                // Calculate how many full groups are needed
                int groupCount = (a.second + a.first) / groupSize;
                result += groupCount * groupSize;
            }
        }

        return result;
    }
};
