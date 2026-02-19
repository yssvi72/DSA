//Iterative method to delete node:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int number;
	Node* next;
};

void Push(Node** head, int A)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->number = A;
	n->next = *head;
	*head = n;
}

void deleteN(Node** head, int position)
{
	Node* temp;
	Node* prev;
	temp = *head;
	prev = *head;
	for (int i = 0; i < position; i++) {
		if (i == 0 && position == 1) {
			*head = (*head)->next;
			free(temp);
		}
		else {
			if (i == position - 1 && temp) {
				prev->next = temp->next;
				free(temp);
			}
			else {
				prev = temp;

				// Position was greater than
				// number of nodes in the list
				if (prev == NULL)
					break;
				temp = temp->next;
			}
		}
	}
}

void printList(Node* head)
{
	while (head) {
		if (head->next == NULL)
			cout << "[" << head->number << "] "
				<< "[" << head << "]->"
				<< "(nil)" << endl;
		else
			cout << "[" << head->number << "] "
				<< "[" << head << "]->" << head->next
				<< endl;
		head = head->next;
	}
	cout << endl << endl;
}

// Driver code
int main()
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->next = NULL;
	Push(&list, 1);
	Push(&list, 2);
	Push(&list, 3);

	printList(list);

	// Delete any position from list
	deleteN(&list, 1);
	printList(list);
	return 0;
}

//Recursive method---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// C++ program to delete a node in
// singly linked list recursively

#include <bits/stdc++.h>
using namespace std;

struct node {
	int info;
	node* link = NULL;
	node() {}
	node(int a)
		: info(a)
	{
	}
};

// Deletes the node containing 'info'
// part as val and alter the head of
// the linked list (recursive method)
void deleteNode(node*& head, int val)
{

	// Check if list is empty or we
	// reach at the end of the
	// list.
	if (head == NULL) {
		cout << "Element not present in the list\n";
		return;
	}

	// If current node is the
	// node to be deleted
	if (head->info == val) {
		node* t = head;

		// If it's start of the node head
		// node points to second node
		head = head->link;

		// Else changes previous node's
		// link to current node's link
		delete (t);
		return;
	}
	deleteNode(head->link, val);
}

// Utility function to add a
// node in the linked list
// Here we are passing head by
// reference thus no need to
// return it to the main function
void push(node*& head, int data)
{
	node* newNode = new node(data);
	newNode->link = head;
	head = newNode;
}

// Utility function to print
// the linked list (recursive
// method)
void print(node* head)
{

	// cout<<endl gets implicitly
	// typecasted to bool value
	// 'true'
	if (head == NULL and cout << endl)
		return;
	cout << head->info << ' ';
	print(head->link);
}

int main()
{

	// Starting with an empty linked list
	node* head = NULL;

	// Adds new element at the
	// beginning of the list
	push(head, 10);
	push(head, 12);
	push(head, 14);
	push(head, 15);

	// original list
	print(head);

	// Call to delete function
	deleteNode(head, 20);

	// 20 is not present thus no change
	// in the list
	print(head);

	deleteNode(head, 10);
	print(head);

	deleteNode(head, 14);
	print(head);

	return 0;
}
