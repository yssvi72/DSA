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
// unordered_map<int,int>mp;
// int maxD=0;
// void maxDepth(TreeNode* root, int d){
//     if(root==NULL) return;
//     maxD=max(maxD,d);
//     mp[root->val]=d;
//     maxDepth(root->left,d+1);
//     maxDepth(root->right,d+1);
// }
// TreeNode* LCA(TreeNode* root){
//     if(root==NULL || mp[root->val]==maxD){
//         return root;
//     }
//     TreeNode* leftVal=LCA(root->left);
//     TreeNode* rightVal=LCA(root->right);
//     if(leftVal!=NULL && rightVal!=NULL) return root;
//     if(leftVal!=NULL) return leftVal;
//     return rightVal;
// }
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
//         maxDepth(root,0);
//         return LCA(root);
//     }


// ONE PASS SOLUTION
pair<int,TreeNode*> helper(TreeNode* root){
    if(root==NULL) return {0,NULL};
    auto l=helper(root->left);
    auto r=helper(root->right);
    if(l.first == r.first){
        return {l.first+1,root};
    }else if(l.first>r.first){
        return {l.first+1,l.second};
    }else{
        return {r.first+1,r.second};
    }
}
TreeNode* lcaDeepestLeaves(TreeNode* root){
    return helper(root).second;
}
};
