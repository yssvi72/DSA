class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
       int n=nums[0].length();
       vector<int>lol;
       int chal;
       int i;
        for( i=0;i<nums.size();i++)
        {
            chal=0;
            for(int j=0;j<n;j++)
            {
                chal=chal+(nums[i][j]-'0')*pow(2,n-j-1);
            }
            lol.push_back(chal);
        }
        int c=0;
        for( i=0;i<pow(2,n);i++)
        {
                if (find(lol.begin(), lol.end(), i) == lol.end()) {
                    c=i;
                    break;
            }
        }
        string vro="";
        cout<<c;
        while(n>0)
        {
            int x=c%2;
            vro=vro+to_string(x);
            c=c/2;
            n--;
        }
       reverse(vro.begin(),vro.end());
        return vro;
    }
};
