class Solution {
public:
    void generateHappyStrings(int n, string current, vector<string>& result, char lastChar) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (ch != lastChar) {
                generateHappyStrings(n, current + ch, result, ch);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        generateHappyStrings(n, "", happyStrings, ' ');

        return (k <= happyStrings.size()) ? happyStrings[k - 1] : "";
    }
};
