// A balanced binary tree is a binary tree that follows the 3 conditions:
// The height of the left and right tree for any node does not differ by more than 1.
// The left subtree of that node is also balanced.
// The right subtree of that node is also balanced.

// Intuition Approach ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//For a Balanced Binary Tree, Check left subtree height and right subtree height for every node present in the tree. Hence, traverse the tree recursively and calculate the height of left and right subtree from every node, and whenever the condition of Balanced tree violates, simply return false.
// Condition for Balanced Binary Tree:  Absolute( Left Subtree Height – Right Subtree Height ) <= 1
//TC--O(n2) SC->O(1)

//Post-order traversal---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Start traversing the tree recursively and do work in Post Order.
//For each call, caculate the height of the root node, and return it to previous calls.  
//Simultaneously, in the Post Order of every node , Check for condition of balance as information of left and right subtree height is available.
//If it is balanced , simply return height of current node and if not then return -1.
//Whenever the subtree result is -1 , simply keep on returning -1.
class Solution {

public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight (root) != -1;
    }

    int dfsHeight (TreeNode *root) {

        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);

        if (leftHeight == -1) 
            return -1;
        
        int rightHeight = dfsHeight (root -> right);

        if (rightHeight == -1) 
            return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        return max (leftHeight, rightHeight) + 1;
    }
};
//TC->O(n) , SC-->O(1)+Extra-space
