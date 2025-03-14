class Solution {
public:
    bool canallocate(vector<int>& candies, long long k,long long mid){
        long long total=0;
        for(int candi:candies){
            total+=(candi/mid);
            if(total>=k)
            return true;
        }
        return total>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long totalchild=0;
        long long left=1;
        long long right=*max_element(candies.begin(),candies.end());
        int result=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(canallocate(candies,k,mid)){
                result=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }

        }
        return result;

    }
};
