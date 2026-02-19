/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minSwapsToSort(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int, int>> paired(n);
        for (int i = 0; i < n; i++) {
            paired[i] = {arr[i], i};
        }

        sort(paired.begin(), paired.end());

        vector<bool> visited(n, false);

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || paired[i].second == i) {
                continue;
            }

            int cycle_size = 0;
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                x = paired[x].second;
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            cnt+=minSwapsToSort(temp);
        }
        return cnt;
    }
};
