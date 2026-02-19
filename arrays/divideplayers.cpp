class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size();
        int x = skill[0]+skill[n-1];
        long long prod = skill[0]*skill[n-1];
        for(int i=1;i<n/2;i++){
            if(skill[i]+skill[n-i-1]!=x){
                return -1;
            }
            long long p = (skill[i]*skill[n-i-1]);
            prod+=p;

        }
        return prod;
    }
};
