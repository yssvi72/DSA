class SegTree{
    vector<int> t;
public:
    SegTree(int n)
    {
        t.resize(4*n, 0);
    }

    void insert(int i, int l, int r, int pos)
    {
        if (pos < l || pos > r || l > r)
        {
            return;
        }

        if (l == r)
        {
            t[i] = 1;
            return;
        }

        int mid = l + (r - l)/2;

        insert(2*i, l, mid, pos);
        insert(2*i+1, mid+1, r, pos);

        t[i] = t[2*i] + t[2*i+1];
    }

    int query(int i, int l, int r, int lq, int rq)
    {
        if (l > r || lq > rq || r < lq || rq < l)
        {
            return 0;
        }

        if (lq <= l && r <= rq)
        {
            return t[i];
        }

        int mid = l + (r-l)/2;

        return query(2*i, l, mid, lq, rq) + query(2*i+1, mid+1, r, lq, rq);
    }
};


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {

        map<int,int> end;


        int n = nums1.size();
        vector<long long> left(n, 0);
        vector<long long> right(n, 0);

        SegTree st(n);

        for (int i = 0; i<nums1.size(); i++)
        {
            end[nums2[i]] = i;
        }

        long long ans = 0;

        for (int i = 0; i<nums1.size(); i++)
        {
            long long count = st.query(1, 0, n-1, 0, end[nums1[i]]-1);
            left[i] = count;
            st.insert(1, 0, n-1, end[nums1[i]]);
        }

        SegTree st2(n);

        for (int i = n-1; i>=0; i--)
        {
            long long count = st2.query(1, 0, n-1, end[nums1[i]]+1, n-1);
            right[i] = count;
            st2.insert(1, 0, n-1, end[nums1[i]]);
        }

        for (int i = 0; i<n; i++)
        {
            ans += left[i] * right[i];
        }

        return ans;
    }
};
