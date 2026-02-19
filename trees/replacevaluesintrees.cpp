class Solution {
public:
    void traverse(TreeNode* root, vector<int>& levelSum) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                levelSum.push_back(sum);
                sum = 0;
                if (q.size() == 0 && curr == NULL) {
                    break;
                }
                q.push(NULL);
            } else {
                sum += curr->val;
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        // store the sum for each level using level order traversal..
        vector<int> levelSum;
        traverse(root, levelSum);
        //0TH AND 1ST LEVELS DO NOT HAVRE COUSINS SO THEY WILL STORE 0
        TreeNode *temp=root;
        //use level order again and update the nodes 
        queue<TreeNode*>q;
        //update the root and 1st level nodes..
        temp->val=0;
        if(temp->left!=NULL){
            temp->left->val=0;
            q.push(temp->left);}
        if(temp->right!=NULL){
            temp->right->val=0;
            q.push(temp->right);}
        q.push(NULL);
        int level=2;
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr==NULL){
                //go to next level but befroe it update the values..
                level++;
                if(q.size()==0){
                    break;}
                q.push(NULL);
            }
            else{
                //find the sum of the sibilings first..
                int sib_sum=0;
                if(curr->left!=NULL){
                    sib_sum+=curr->left->val;}
                if(curr->right!=NULL){
                    sib_sum+=curr->right->val;}
                //now update..
                if(curr->left!=NULL){
                    curr->left->val=levelSum[level]-sib_sum;
                    q.push(curr->left);}
                if(curr->right!=NULL){
                    curr->right->val=levelSum[level]-sib_sum;
                    q.push(curr->right);}}}
            return root;}};
