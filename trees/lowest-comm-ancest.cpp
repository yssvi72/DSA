class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      TreeNode* left_rtn = nullptr, *right_rtn = nullptr;
        if(root->left != nullptr) 
            left_rtn = lowestCommonAncestor(root->left, p, q);
        if(root->right != nullptr)
            right_rtn = lowestCommonAncestor(root->right, p, q);
        if(left_rtn != nullptr && right_rtn != nullptr) return root;
        if(root == p || root == q) return root;
        return (left_rtn != nullptr)? left_rtn:right_rtn;   
    }
}
