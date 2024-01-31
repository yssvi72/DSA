//The height of the tree is the number of vertices in the tree from the root to the deepest node. The height of an empty tree is 0 and the height of a tree with single node is 1.

//Approach 1 : Recursion  T: O(n), S: O(n) ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

//Approach 2: Queue to implement T:O(n) S:O(n)------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int depth = 0;
    queue<Node*> q;
    // Pushing first level element along with NULL
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        // When NULL encountered, increment the value
        if (temp == NULL) {
            depth++;
        }
        // If NULL not encountered, keep moving
        if (temp != NULL) {
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        // If queue still have elements left,
        // push NULL again to the queue.
        else if (!q.empty()) {
            q.push(NULL);
        }
    }
    return depth;
// Approach 3 : Using Level Order Traversal T: O(n) S: O(n)------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// This method also uses the concept of Level Order Traversal but we wont be adding null in the Queue. Simply increase the counter when the level increases and push the children of current node into the queue, then remove all the nodes from the queue of the current Level.
int height(Node* root)
{
  // Initialising a variable to count the
  // height of tree
  queue<Node*> q;
  q.push(root);
  int height = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      Node* temp = q.front();
      q.pop();
      if (temp->left != NULL) {
        q.push(temp->left);
      }
      if (temp->right != NULL) {
        q.push(temp->right);
      }
    }
    height++;
  }
  return height;
}
 
