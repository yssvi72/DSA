class Solution {
public:
    string reverseParentheses(string s) {
        deque<string> st;
        string cur = "";
        for(int i=0;i<s.size();++i){
            if(s[i] == '('){
                st.push_back(cur);
                cur = "";
            }
            else if(s[i] == ')'){
                reverse(cur.begin(),cur.end());
                cur = st.back()+cur;
                st.pop_back();
            }else cur += s[i];
        }
        return cur;
    }
};
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string ans = "";
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else if(s[i] == ')')
            {
                int start = st.top()+1;
                int end = i;

                reverse(s.begin()+start, s.begin()+end);
                st.pop();
            }
        }

        for(auto &ch : s)
        {
            if(ch != '(' && ch != ')')
            {
                ans += ch;
            }
        }

        return ans;
    }
};
