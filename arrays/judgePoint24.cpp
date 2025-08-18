class Solution {
public:
    struct Expr {
        double val;
        string s;
    };

    bool judgePoint24(vector<int>& cards) {
        vector<Expr> nums;
        for (int c : cards) nums.push_back({(double)c, to_string(c)});
        return solve(nums);
    }

    bool solve(vector<Expr>& nums) {
        if (nums.size() == 1) {
            if (fabs(nums[0].val - 24.0) < 1e-6) {
                // You can print the expression if you want
                // cout << nums[0].s << endl;
                return true;
            }
            return false;
        }

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                vector<Expr> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                for (auto& e : combine(nums[i], nums[j])) {
                    next.push_back(e);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<Expr> combine(const Expr& a, const Expr& b) {
        vector<Expr> res;
        res.push_back({a.val + b.val, "(" + a.s + "+" + b.s + ")"});
        res.push_back({a.val - b.val, "(" + a.s + "-" + b.s + ")"});
        res.push_back({b.val - a.val, "(" + b.s + "-" + a.s + ")"});
        res.push_back({a.val * b.val, "(" + a.s + "*" + b.s + ")"});
        if (fabs(b.val) > 1e-6)
            res.push_back({a.val / b.val, "(" + a.s + "/" + b.s + ")"});
        if (fabs(a.val) > 1e-6)
            res.push_back({b.val / a.val, "(" + b.s + "/" + a.s + ")"});
        return res;
    }
};
