class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> invBox;
        for (int i = m - 1; i >= 0; i--) {
            vector<char> tmp;
            int c_sp = 0;
            for (int j = n - 1; j >= 0; j--) {

                if (box[i][j] == '*') {
                    if (c_sp > 0) {
                        while (c_sp>0) {
                            tmp.push_back('.');
                            c_sp--;
                        }
                       
                    }
                    tmp.push_back('*');
                } else if (box[i][j] == '#') {
                    tmp.push_back('#');
                } else {
                    c_sp++;
                }
            }
            if (c_sp > 0) {
                while (c_sp--) {
                    tmp.push_back('.');
                }
            }

            //Output for Testing
            // cout << endl << "Test " << m - i << "th Row" << endl;
            // for (auto it : tmp)
            //     cout << it;
            reverse(tmp.begin(), tmp.end());
            invBox.push_back(tmp);
        }

        //Output for Testing
        // cout << endl;
        // for (auto& row : invBox) {
        //     for (auto& ii : row) {
        //         cout << ii;
        //     }
        //     cout << endl;
        // }

        // cout << m << n << endl;

        vector<vector<char>> res;
        for (int i = 0; i < n; i++) {
            vector<char> tmp;
            for (int j = 0; j < m; j++) {
                tmp.push_back(invBox[j][i]);
            }
            res.push_back(tmp);
        }
        //Output for Testing
        // for (auto& row : res) {
        //     for (auto& ii : row) {
        //         cout << ii;
        //     }
        //     cout << endl;
        // }
        return res;
    }
};
