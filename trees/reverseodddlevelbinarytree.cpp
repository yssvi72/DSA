/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* L, TreeNode* R, int level){
        if(R== nullptr || L==nullptr){
            return;
        }
        if(level %2==1){
            int temp= L->val;
            L->val= R->val;
            R->val=temp;
        }
        solve(L->left, R->right, level+1);
        solve( L->right, R->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left, root->right, 1);
        return root;
    }
};
