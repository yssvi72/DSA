//Given two numbers represented by two linked lists, the task is to write a function that returns the sum of the two linked lists in the form of a list.
//Note: It is not allowed to modify the lists. Also, not allowed to use explicit extra space (Hint: Use Recursion).
//Example :Input: First List: 5->6->3, Second List: 8->4->2  . Output: Resultant list: 1->4->0->5 , Explanation: Sum of 563 and 842 is 1405
// A C++ recursive program to add two linked lists
#include <bits/stdc++.h>
using namespace std;

// A linked List Node
class Node {
public:
	int data;
	Node* next;
};

typedef Node node;

/* A utility function to insert
a node at the beginning of linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node[(sizeof(Node))];

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

// A utility function to swap two pointers
void swapPointer(Node** a, Node** b)
{
	node* t = *a;
	*a = *b;
	*b = t;
}

/* A utility function to get size of linked list */
int getSize(Node* node)
{
	int size = 0;
	while (node != NULL) {
		node = node->next;
		size++;
	}
	return size;
}

// Adds two linked lists of same size
// represented by head1 and head2 and returns
// head of the resultant linked list. Carry
// is propagated while returning from the recursion
node* addSameSize(Node* head1, Node* head2, int* carry)
{
	// Since the function assumes linked lists are of same
	// size, check any of the two head pointers
	if (head1 == NULL)
		return NULL;

	int sum;

	// Allocate memory for sum node of current two nodes
	Node* result = new Node[(sizeof(Node))];

	// Recursively add remaining nodes and get the carry
	result->next
		= addSameSize(head1->next, head2->next, carry);

	// add digits of current nodes and propagated carry
	sum = head1->data + head2->data + *carry;
	*carry = sum / 10;
	sum = sum % 10;

	// Assign the sum to current node of resultant list
	result->data = sum;

	return result;
}

// This function is called after the
// smaller list is added to the bigger
// lists's sublist of same size. Once the
// right sublist is added, the carry
// must be added toe left side of larger
// list to get the final result.
void addCarryToRemaining(Node* head1, Node* cur, int* carry,
						Node** result)
{
	int sum;

	// If diff. number of nodes are not traversed, add carry
	if (head1 != cur) {
		addCarryToRemaining(head1->next, cur, carry,
							result);

		sum = head1->data + *carry;
		*carry = sum / 10;
		sum %= 10;

		// add this node to the front of the result
		push(result, sum);
	}
}

// The main function that adds two linked lists
// represented by head1 and head2. The sum of
// two lists is stored in a list referred by result
void addList(Node* head1, Node* head2, Node** result)
{
	Node* cur;

	// first list is empty
	if (head1 == NULL) {
		*result = head2;
		return;
	}

	// second list is empty
	else if (head2 == NULL) {
		*result = head1;
		return;
	}

	int size1 = getSize(head1);
	int size2 = getSize(head2);

	int carry = 0;

	// Add same size lists
	if (size1 == size2)
		*result = addSameSize(head1, head2, &carry);

	else {
		int diff = abs(size1 - size2);

		// First list should always be larger than second
		// list. If not, swap pointers
		if (size1 < size2)
			swapPointer(&head1, &head2);

		// move diff. number of nodes in first list
		for (cur = head1; diff--; cur = cur->next)
			;

		// get addition of same size lists
		*result = addSameSize(cur, head2, &carry);

		// get addition of remaining first list and carry
		addCarryToRemaining(head1, cur, &carry, result);
	}

	// if some carry is still there, add a new node to the
	// front of the result list. e.g. 999 and 87
	if (carry)
		push(result, carry);
}

// Driver code
int main()
{
	Node *head1 = NULL, *head2 = NULL, *result = NULL;

	int arr1[] = { 9, 9, 9 };
	int arr2[] = { 1, 8 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	// Create first list as 9->9->9
	int i;
	for (i = size1 - 1; i >= 0; --i)
		push(&head1, arr1[i]);

	// Create second list as 1->8
	for (i = size2 - 1; i >= 0; --i)
		push(&head2, arr2[i]);

	addList(head1, head2, &result);

	printList(result);

	return 0;
}

//Method 2:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
// C++ Iterative program to add two linked lists 
#include <bits/stdc++.h> 
using namespace std; 

// A linked List Node 
class Node 
{ 
	public: 
	int data; 
	Node* next; 
};

// to push a new node to linked list
void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node[(sizeof(Node))]; 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list of the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
}

// to add two new numbers
Node* addTwoNumList(Node* l1, Node* l2) {
	stack<int> s1,s2;
	while(l1!=NULL){
		s1.push(l1->data);
		l1=l1->next;
	}
	while(l2!=NULL){
		s2.push(l2->data);
		l2=l2->next;
	}
	int carry=0;
	Node* result=NULL;
	while(s1.empty()==false || s2.empty()==false){
		int a=0,b=0;
		if(s1.empty()==false){
			a=s1.top();s1.pop();
		}
		if(s2.empty()==false){
			b=s2.top();s2.pop();
		}
		int total=a+b+carry;
		Node* temp=new Node();
		temp->data=total%10;
		carry=total/10;
		if(result==NULL){
			result=temp;
		}else{
			temp->next=result;
			result=temp;
		}
	}
	if(carry!=0){
		Node* temp=new Node();
		temp->data=carry;
		temp->next=result;
		result=temp;
	}
	return result;
}

// to print a linked list
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout<<node->data<<" "; 
		node = node->next; 
	} 
	cout<<endl; 
}

// Driver Code
int main() 
{ 
	Node *head1 = NULL, *head2 = NULL; 

	int arr1[] = {5, 6, 7}; 
	int arr2[] = {1, 8}; 

	int size1 = sizeof(arr1) / sizeof(arr1[0]); 
	int size2 = sizeof(arr2) / sizeof(arr2[0]); 

	// Create first list as 5->6->7 
	int i; 
	for (i = size1-1; i >= 0; --i) 
		push(&head1, arr1[i]); 

	// Create second list as 1->8 
	for (i = size2-1; i >= 0; --i) 
		push(&head2, arr2[i]); 
	
	Node* result=addTwoNumList(head1, head2);
	printList(result); 

	return 0; 
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int value){
		val = value;
		next = NULL;
	}
};

void push_front(Node** head, int new_val){
	Node* new_node = new Node(new_val);
	new_node->next = *head;
	*head = new_node;
}

void printList(Node* head){
	Node* i = head;
	while(i){
		cout<<i->val<<" ";
		i = i->next;
	}
	cout<<"\n";
}

// function to add 2 numbers given as linked lists
Node* add(Node* l1, Node* l2){
	Node* ans = new Node(0);
	Node* curr = ans;
	int carry = 0;
	while(l1 || l2){
		int sum = 0;
		if(l1) sum += l1->val;
		if(l2) sum += l2->val;
		sum += carry;

		curr->next = new Node(sum%10);
		curr = curr->next;

		carry = sum/10;

		if(l1) l1 = l1->next;
		if(l2) l2 = l2->next;
	}

	if(carry){
		curr->next = new Node(carry);
	}
	ans = ans->next;
	return ans;
}

int main(){
	Node* l1 = NULL;

	push_front(&l1, 1);
	push_front(&l1, 5);

	Node* l2 = NULL;

	push_front(&l2, 3);
	push_front(&l2, 9);
	push_front(&l2, 7);

	// l1-> 5 1 = 15
	// l2-> 7 9 3 = 397

	Node* sum = add(l1,l2);

	printList(sum);
	// 2 1 4	 = 412
}


