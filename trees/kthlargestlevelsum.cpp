class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<long long , vector<long long > , greater<long long>> pq;
        q.push(root); 
        while (!q.empty()) {
            int l = q.size(); 
            long long  s = 0;
            for (int i = 0 ; i < l ; i ++) {
                TreeNode* t = q.front();
                q.pop();
                s += t->val;
                if (t->left != nullptr) {
                    q.push(t->left); 
                } 
                if (t->right != nullptr) {
                    q.push(t->right); 
                } 
            }
            
            pq.push(s); 
            
            if (pq.size() > k) {
                pq.pop(); 
            }
        }        

        if (pq.size() < k) {
            return -1;
        }


        


        return pq.top(); 
    }
};
