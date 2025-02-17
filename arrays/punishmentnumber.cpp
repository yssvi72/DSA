class Solution {
public:
bool func(string s,int j,int num,int m)
{
    if(j==s.size())
    {
        if(num==m)return true;
        return false;
    }
    int number=0;
    for(int k=j;k<s.size();k++)
    {
        number=(number*10)+(s[k]-'0');
        if(func(s,k+1,num+number,m))return true;
    }
    return false;
}
    int punishmentNumber(int n) {
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        string s=to_string(i*i);
        if(func(s,0,0,i))sum+=(i*i);
    }    
    return sum;
    }
};
