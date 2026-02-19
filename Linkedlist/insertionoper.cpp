/*Given a Linked List, the task is to insert a new node in this given Linked List at the following positions: 
i. At the front of the linked list  
ii. After a given node. 
iii. At the end of the linked list.
*/

//Insertion at beginning------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/* Approach: 
Make the first node of Linked List linked to the new node
Remove the head from the original first node of Linked List
Make the new node as the Head of the Linked List.
*/
void insertFront(Node** head, int data){
    Node* new_node = new Node();
    // assign data
    new_node->data = data; 
    // change the next node of this newNode 
    // to current head of Linked List
    new_node->next = *head;
     // new_node should become the new head of Linked List
    *head = new_node;
     cout << "Inserted Item: " << new_node->data << endl;
}

//Insertion at randomly---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Given a node prev_node, insert a new node after the given prev_node
void insertAfter(Node* prev_node, int new_data)
{// 1. Check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
    // 2. Allocate new node
    Node* new_node = new Node();
    // 3. Put in the data
    new_node->data = new_data;
    // 4. Make next of new node as
    // next of prev_node
    new_node->next = prev_node->next;
     // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node;
}

//Insertion at end--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void insertEnd(Node** head, int data)
{  Node* freshNode = new Node();
    freshNode->data = data;
    // since this will be the last node so it will point to NULL
    freshNode->next = NULL;
     //need this if there is no node present in linked list at all
    if(*head==NULL)
    {
        *head = freshNode;
        cout << freshNode->data << " inserted" << endl; 
        return; 
    }
    struct Node* temp = *head; 
    // traverse to the last node of Linked List 
    while(temp->next!=NULL)
     temp = temp->next;
    // assign last node's next to this freshNode
    temp->next = freshNode;
    cout << freshNode->data << " inserted" << endl;
}

//Display node-----------------------
void display(Node* node)
{

    //as linked list will end when Node is Null
    while(node!=NULL)
    {
        cout << node->data << " "; 
        node = node->next;
    }
    cout << endl;
}
