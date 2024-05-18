class Solution {
public:
    int distributeCoins(TreeNode* root) {
       int moves = 0;
	costToDistribute(root, moves);
	return moves;
    }
    int costToDistribute(TreeNode *root, int& moves) {
	if(!root) return 0;
	else if(root && !root->left && !root->right) {
		// no new moves for this subtree
		return 1-root->val;
	}
	int leftCost = 0, rightCost = 0;
	if(root->left) {
		leftCost = costToDistribute(root->left, moves);
	}
	if(root->right) {
		rightCost = costToDistribute(root->right, moves);
	}
	moves+=abs(leftCost) + abs(rightCost); //assume all wealth to be at the root
	int total_cost = leftCost + rightCost + (1-root->val);
	return total_cost;
}
};
