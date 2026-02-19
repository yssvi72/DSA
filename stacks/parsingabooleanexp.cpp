class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        for (char ch : exp) {
            if (ch == ',' || ch == '(') {
                continue;
            }

            if (ch == 't' || ch == 'f' || ch == '&' || ch == '|' || ch == '!') {
                st.push(ch);
            } else if (ch == ')') {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topChar = st.top();
                    st.pop();
                    if (topChar == 't')
                        hasTrue = true;
                    else
                        hasFalse = true;
                }

                char topOperator = st.top();
                st.pop();
                if (topOperator == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else if (topOperator == '|') {
                    st.push(hasTrue ? 't' : 'f');
                } else {
                    st.push(hasFalse ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};
