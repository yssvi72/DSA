/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class FindElements {
private:
    unordered_set<int> valuesEncountered;

    void recoverTreeFromCatastrophe(TreeNode* node, int parentValue) {
       //bfs
       if(node == nullptr) {
            return;
       }

       queue<TreeNode*> que;
       node -> val = parentValue;

       que.push(node);
       valuesEncountered.insert(node -> val);

       //bfs starts
       while(!que.empty()) {
            TreeNode* currentNode = que.front();
            que.pop();

            int currentVal = currentNode -> val;

            if(currentNode -> left != nullptr) {
                currentNode -> left -> val = 2 * currentVal + 1;
                valuesEncountered.insert(currentNode -> left -> val);
                que.push(currentNode -> left);
            }

            if(currentNode -> right != nullptr) {
                currentNode -> right -> val = 2 * currentVal + 2;
                valuesEncountered.insert(currentNode -> right -> val);
                que.push(currentNode -> right);
            }
       }
    }
public:
    FindElements(TreeNode* root) {
        recoverTreeFromCatastrophe(root, 0);
    }

    bool find(int target) {
            //maintain a sorted list of elements maybe in form of any data structure such that searching becomes efficient 
            //using unordered_set

        return valuesEncountered.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
