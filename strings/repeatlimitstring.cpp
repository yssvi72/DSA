#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);

        // Step 1: Frequency array
        for (char c : s) {
            freq[c - 'a']++;
        }

        string result;
        int index = 25;

        // Step 2: Build the result string
        while (index >= 0) {
            if (freq[index] == 0) {
                index--;
                continue;
            }

            int repeatCount = min(freq[index], repeatLimit);
            result.append(repeatCount, 'a' + index);
            freq[index] -= repeatCount;

            if (freq[index] > 0) {
                int nextIndex = index - 1;
                while (nextIndex >= 0 && freq[nextIndex] == 0) {
                    nextIndex--;
                }

                if (nextIndex < 0) break;

                result += 'a' + nextIndex;
                freq[nextIndex]--;
            } else {
                index--;
            }
        }

        return result;
    }
};
