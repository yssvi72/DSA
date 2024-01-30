//For two trees ‘a’ and ‘b’ to be mirror images, the following three conditions must be true: 
// 1. Their root node’s key must be same
// 2. Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
// 3. Right subtree of ‘a’ and left subtree of ‘b’ are mirror.

struct Node
{   //A binary tree node has data, pointer to left child and a pointer to right child 
    int data;
    Node* left, *right;
};

// Approach 1: Brute force/ Beginner-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool areMirror(Node* a, Node* b)
{
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        return true;
 
    // If only one is empty
    if (a==NULL || b == NULL)
        return false;
 
    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  a->data == b->data &&
            areMirror(a->left, b->right) &&                                                  //left of 'a' should be right of 'b' 
            areMirror(a->right, b->left);                                                    //right of 'a' should be left of 'b' 
}
//TC -O(n) , SC-O(h) where h is height of binary tree

//Approach 2: Iterative Approach------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Iterative algorithm that uses a stack to keep track of the nodes being traversed. Uses two stacks for two trees. Pops a node from both stacks, checks if their data is equal, and then pushes their left and right children onto the stacks in the opposite0 order
bool isMirrorIterative(Node* root1, Node* root2)
{    //if both empty , mirror hai
    if (root1 == NULL && root2 == NULL)
        return true;
     //if one is and one is not , not mirror
    if (root1 == NULL || root2 == NULL)
        return false;
  
    // Stack node and push root of both tree
    stack<Node*> s1, s2;
    s1.push(root1);
    s2.push(root2);
     
    while (!s1.empty() && !s2.empty())
    {    //Till both stack elements have emptied 
        Node* curr1 = s1.top();  //Point top
        s1.pop(); //Pop top most element
        Node* curr2 = s2.top();   //Point top
        s2.pop();  //Pop top most element
         
        if (curr1->data != curr2->data)  //If current data i.e is popped from both stacks are not equal , return false 
            return false;
         
        if (curr1->left != NULL && curr2->right != NULL)  
        {   //Mirror condition
            s1.push(curr1->left);  //Push in left
            s2.push(curr2->right);  //Push in right
        }
        else if (curr1->left != NULL || curr2->right != NULL)
            return false;       // Not equal , false
         
        if (curr1->right != NULL && curr2->left != NULL)
        {
            s1.push(curr1->right); //Vice versa of above case
            s2.push(curr2->left);  
        }
        else if (curr1->right != NULL || curr2->left != NULL)
            return false;     // Not equal  , false
    } 
     
    if (!s1.empty() || !s2.empty())
        return false;       //Till the time , if one of the stack got empty before than other , please return false
     
    return true;           // Else for all other cases , return true
}
//TC--> O(n) , SC-->O(h)
