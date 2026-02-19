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
    int pre = 0;  // Pointer for preorder traversal
    int post = 0; // Pointer for postorder traversal

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* curr = new TreeNode(preorder[pre++]); // Create node from preorder value
        
        // Recursively build left subtree if current node is not at correct postorder position
        if (curr->val != postorder[post])  
            curr->left = constructFromPrePost(preorder, postorder);

        // Recursively build right subtree if current node is still not at correct postorder position
        if (curr->val != postorder[post])  
            curr->right = constructFromPrePost(preorder, postorder);

        post++; // Move to the next postorder index after processing
        return curr;
    }
};
