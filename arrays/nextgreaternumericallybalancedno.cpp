class Solution {
private:
    set<int> all;
public:
    int nextBeautifulNumber(int n) {
        vector<string> v;
        for(int i=1;i<=6;++i) {
            string t = "";
            for(int j=1;j<=i;++j) {
                t += (char)(i + '0');
            }
            v.push_back(t);
            all.insert(stoi(t));
        }

        auto perm = [&](auto&& self, set<int>& taken, string& t, string& curr)->void{
            if(curr.length() == t.length()) {
                all.insert(stoi(curr));
                return;
            }

            for(int i=0;i<t.length();++i) {
                if(taken.find(i) == taken.end()) {
                    curr += t[i];
                    taken.insert(i);
                    self(self, taken, t, curr);
                    curr.pop_back();
                    taken.erase(i);
                }
            }
        };
