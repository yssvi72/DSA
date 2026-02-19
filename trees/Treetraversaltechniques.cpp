//Traversal techniques of binary tree:

//Declaration of node 
struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//1. Inorder ( LEFT , Root-Node , RIGHT)
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    // First recur on left subtree
    printInorder(node->left);
 
    // Now deal with the node
    cout << node->data << " ";
 
    // Then recur on right subtree
    printInorder(node->right);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//2. Preorder (Root-Node , Left , Right)
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    // Deal with the node
    cout << node->data << " ";

    // Recur on left subtree
    printPreorder(node->left);

    // Recur on right subtree
    printPreorder(node->right);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//3. Postorder (Left , Right , Root-Node)
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // First recur on left subtree
    printPostorder(node->left);
 
    // Then recur on right subtree
    printPostorder(node->right);
 
    // Now deal with the node
    cout << node->data << " ";
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Driver code for having atleast some node for traversal to work:
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
 
    // Function call
    cout << "Inorder traversal of binary tree is: \n";
    printInorder(root);
    cout << "Preorder traversal of binary tree is: \n";
    printPreorder(root);
    cout << "Postorder traversal of binary tree is: \n";
    printPostorder(root);
    return 0;
}
