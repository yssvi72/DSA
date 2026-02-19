class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;
        string ans = "";
        int n = word.size();
        int max_len = n - (numFriends - 1);
        vector<int> indices;
        char mx =' ';
        for (int i = 0; i < n; i++) {
            mx = max(mx, word[i]);
        }
        cout<<mx<<endl;
        for (int i = 0; i < n; i++) {
            if (word[i] == mx) {
                indices.push_back(i);
            }
        }
        for (int i = 0; i < indices.size(); i++) {
            int s = min(max_len, (n - indices[i]));
            string temp = word.substr(indices[i], s);
            ans = max(ans, temp);
        }
        return ans;
    }
};
