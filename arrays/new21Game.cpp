class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> p(n+1, 0.0);
        p[0] = 1.0;

        double res = 0.0;
        double probSum = (k == 0) ? 0.0 : 1.0;

        for (int i = 1; i <= n; i++) {
            p[i] = probSum / maxPts;
            if (i < k) {
                probSum += p[i];
            }
            if (i - maxPts >= 0 && i - maxPts < k) {
                probSum -= p[i - maxPts];
            }
        }

        for (int i = k; i <= n; i++) {
            res += p[i];
        }
        return res;
    }
};
