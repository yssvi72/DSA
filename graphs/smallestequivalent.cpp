class Solution {
public:
std::string smallestEquivalentString(std::string s1, std::string s2, std::string baseStr) {
        char eqq[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
                        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
                        'u', 'v', 'w', 'x', 'y', 'z'};
        for(int i = 0; i < s1.length(); i++) {
            char eqc1 = eqq[s1[i] - 'a'];
            char eqc2 = eqq[s2[i] - 'a'];

            char max_c = std::max(eqc1, eqc2);
            char min_c = std::min(eqc1, eqc2);

            int max_c_pos = eqq[max_c - 'a'] - 'a';

            for(int j = max_c_pos; j<26; j++) {
                if(eqq[j] == max_c) {
                    eqq[j] = min_c;
                }
            }
        }

        for(auto& c: baseStr) {
            c = eqq[c-'a'];
        }

        return baseStr;
    }
};
