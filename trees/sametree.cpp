// Given the roots p and q of two binary trees.
// We need to check whether two trees are said to be same i.e if they are structurally identical and the nodes have same value.
//Input: p=[1,2,3] and q=[1,2,3] , Output: true

//Approach 1: Beginner/ Basic--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool isSameTree(TreeNode *p, TreeNode *q)
   { // As we want to return 'yes' or 'no' in the output , that is why we have taken  bool
      if(!p&&!q) {  // Check if p i.e root node is equal to q , that is both root should be same then  only display true 
                   return true; 
                 }
      if(!p||!q) { // If either one of the root is smaller or bigger i.e not equal , return false
                   return false;
                 }
     
      // Now check for values of node p and q 
      if(p->val!=q->val) // If values are not same , return false
                        return false;

     // Return as a whole by checking left node of p with that of q and right node of p with that of q 
    return isSameTree(p->left && q->left) && isSameTree(p->right && q->right);  // As it is and product so if both will be true , then only it will return true , else in all cases false
   }
         
                   
