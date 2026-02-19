class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right)
            return root->val;
        int leftVal = evaluateTree(root->left);
        int rightVal = evaluateTree(root->right);
        if(root->val == 2) {
            root->val = leftVal or rightVal;
        }
        else {
            root->val = leftVal and rightVal;
        }
        return root->val; 
    }
};
