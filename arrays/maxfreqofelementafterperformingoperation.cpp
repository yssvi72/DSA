class Solution {
    public int hig(int[] a, int i, int n, int val) {
        int l=i+1, r=n, mid;
        while (l<r) {
            mid=l+r>>1;
            if (a[mid] > val) r=mid;
            else l=mid+1;
        }
        return l;
    }
    public int low(int[] a, int n, int val) {
        int l=0, r=n, mid;
        while (l<r) {
            mid=l+r>>1;
            if (a[mid] >= val) r=mid;
            else l=mid+1;
        }
        return r;
    }
    public int maxFrequency(int[] a, int k, int o) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i:a) mp.put(i, mp.getOrDefault(i, 0)+1);
        int n=a.length, ans=1;
        Arrays.sort(a);
        for (int i=0; i<n; i++) {
            ans=Math.max(ans, Math.min(o+mp.getOrDefault(a[i]-k, 0), hig(a, i, n, a[i])-low(a, n, a[i]-2*k)));
            ans=Math.max(ans, Math.min(o+mp.getOrDefault(a[i], 0), hig(a, i, n, a[i]+k)-low(a, n, a[i]-k)));
            ans=Math.max(ans, Math.min(o+mp.getOrDefault(a[i]+k, 0), hig(a, i, n, a[i]+k*2)-low(a, n, a[i]+k)));
        }
        return ans;
    }
}
