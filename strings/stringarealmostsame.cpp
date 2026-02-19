class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
            int len1 = s1.length();
            if(s1==s2) return true;

            int x=-1; 
            int y=-1;
            int temp =0;
            for(int i =0; i<len1; i++){
                if(s1[i]!=s2[i]){
                    temp++;
                    if(temp==1) x=i;
                    else if(temp==2) y=i;
                    else return false;
                }
            }
            return (temp== 2 && s1[x]==s2[y] && s1[y]==s2[x]);
            
    }
};
