class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* newHead = nullptr;
        merge(root1, root2, newHead);
        return newHead;
    }
    void merge(TreeNode* root1, TreeNode* root2, TreeNode*& newNode){
        if(root1 == nullptr && root2 == nullptr){
            return;
        }
        else if(root1 == nullptr){
            newNode = new TreeNode(root2->val, root2->left, root2->right);
            return;
        }
        else if (root2 == nullptr){
            newNode = new TreeNode(root1->val, root1->left, root1->right);
            return;
        }
        
        int value = root1->val + root2->val;
        newNode = new TreeNode(value);
        merge(root1->left, root2->left, newNode->left);
        merge(root1->right, root2->right, newNode->right);
    }
};
