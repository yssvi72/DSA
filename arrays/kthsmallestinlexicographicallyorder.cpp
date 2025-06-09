class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  // We already consider 1

        while (k > 0) {
            long long step = getSteps(n, curr, curr + 1);
            if (step <= k) {
                // Move to next sibling
                curr += 1;
                k -= step;
            } else {
                // Move to child
                curr *= 10;
                k -= 1;  // Count the current node
            }
        }

        return curr;
    }

private:
    // Counts the number of integers with prefix n1 that are <= n
    long long getSteps(int n, long long n1, long long n2) {
        long long steps = 0;
        while (n1 <= n) {
            steps += min((long long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};
