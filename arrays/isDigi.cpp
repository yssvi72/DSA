class Solution {
public:
bool isDigi(char s)
{
    if(s=='0' or s=='1' or s=='2' or s=='3' or s=='4' or s=='5' or s=='6' or s=='7' or s=='8' or s=='9')
    {
        return true;
    }
    else return false;
}
bool isAlpha(char s)
{
    return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z');
}
    string clearDigits(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(st.empty() and isDigi(s[i]))
                continue;
            else if(isAlpha(s[i]))st.push(s[i]);
            else    st.pop();
        }
        // if(st.empty())return true;
        string m="";
        while(!st.empty())
        {
            m+=st.top();
            st.pop();
        }
        string ans="";
        int len=m.size();
        for(int i=len-1;i>=0;i--)
        {
            ans+=m[i];
        }
        return ans;
    }
};
