typedef long long ll;
class Solution {
public:
    ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
        const int n1 = nums1.size(), n2 = nums2.size();
        int pidx1 = 0, pidx2 = 0;
        while (pidx1 < n1 && nums1[pidx1] < 0) ++pidx1;
        while (pidx2 < n2 && nums2[pidx2] < 0) ++pidx2;

        // binary search on kth smallest products
        ll lft = -1e10, rgt = 1e10;
        while (lft <= rgt) {
            ll mid = (lft + rgt) >> 1;
            ll count = 0;
            bool exceed = false;

            // Case 1. Neg × Neg (→ pos)
            // nums1: |--> -5, -4, -3, -2, -1
            // nums2: -5, -4, -3, -2, -1 <--|
            // p/s GREATER neg. i1 & i2 values get SMALLER result
            for (int i1 = 0, i2 = pidx2-1; i1 < pidx1 && i2 >= 0;) {
                if (1LL* nums1[i1] * nums2[i2] > mid) ++i1;
                else {
                    count += pidx1 - i1;
                    --i2;
                    if (count >= k) { exceed = true; break; }
                }
            }

            if (exceed) { rgt = mid - 1; continue;}

            // Case 2. Pos × Neg (→ neg)
            // nums1: |--> +1, +2, +3, +4, +5
            // nums2: |--> -5, -4, -3, -2, -1
            // p/s GREATER pos. i1 & SMALLER neg. i2 get SMALLER result
            for (int i1 = pidx1, i2 = 0; i1 < n1 && i2 < pidx2;) {
                if (1LL* nums1[i1] * nums2[i2] > mid) ++i1;
                else {
                    count += n1 - i1;
                    ++i2;
                    if (count >= k) { exceed = true; break; }
                }
            }

            if (exceed) { rgt = mid - 1; continue;}

            // Case 3. Neg × Pos (→ neg)
            // nums1: -5, -4, -3, -2, -1 <--|
            // nums2: +1, +2, +3, +4, +5 <--|
            // p/s SMALLER neg. i1 & GREATER pos. i2 get SMALLER result
            for (int i1 = pidx1-1, i2 = n2-1; i1 >= 0 && i2 >= pidx2;) {
                if (1LL* nums1[i1] * nums2[i2] > mid) --i1;
                else {
                    count += i1 + 1;
                    --i2;
                    if (count >= k) { exceed = true; break; }
                }

            }

            if (exceed) { rgt = mid - 1; continue;}

            // Case 4. Pos × Pos (→ Pos)
            // nums1: +1, +2, +3, +4, +5 <--|
            // nums2: |--> +1, +2, +3, +4, +5
            // p/s SMALLER pos. i1 & i2 values get SMALLER result
            for (int i1 = n1-1, i2 = pidx2; i1 >= pidx1 && i2 < n2;) {
                if (1LL* nums1[i1] * nums2[i2] > mid) --i1;
                else {
                    count += i1 - pidx1 + 1;
                    ++i2;
                    if (count >= k) { exceed = true; break; }
                }
            }

            if (count < k) lft = mid + 1;
            else rgt = mid - 1;
        } 

        return lft;
    }
};
