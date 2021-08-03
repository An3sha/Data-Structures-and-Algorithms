//Insertion can happen at any place (head, tail, middle) in linkedlist unlike array (only at last)

#include<iostream>
using namespace std;

class node  //each node has two data members - int and node*
{
	public:

	int data;
	node* next;

	node(int d)   // Constructor for the node
	{
		data = d;
		next = NULL;
	}
};

//We can define a Linked List by either using a Class or a Function

// class LinkedList 
// {
// 	node* head;
// 	node* tail;
// public:
// 	LinkedList()
// 	{
// 		head = NULL;
// 		tail = NULL;
// 	}
// 	void insert()
// 	{

// 	}
// };



/* INSERT A NODE AT HEAD 
----------------------------------------------------- T(O(1))*/

void InsertAtHead (node* &head, int data) 		 //Passing a pointer variable by reference
{
	node* n = new node (data);  			 // Allocate new node and do dynamic memory allocation     //node* n = new node();          n -> data = data;
	n -> next = head;				 // Make next of new node as head
	head = n;					 // move head to point to the new node
}


/* INSERT A NODE AFTER A GIVEN NODE
----------------------------------------------------- T(O(1))*/

void InserAfter(node* prev_node, int data)
{
	if(prev_node==NULL)
	{
		cout<<"the given previous node cannot be null";
		return;
	}

	node* n = new node(data);
	n -> next = prev_node -> next;
	prev_node -> next = n;
}	


/* INSERT A NODE AT END
----------------------------------------------------- T(O(n))*/

void InserAtEnd(node* &head, int data)
{
	node* n = new node(data);
	node* last = head;
	n -> next = NULL;				// last node so next is null

	if(head == NULL)				//if the linked list is empty then make new node as head
	{
		head = n;
		return;
	}

	while(last->next != NULL)			// else traverse till the last node
	{
		last = last -> next;
	}

	last -> next = n;				//change the next to last node
	return;
}




void print(node* head)
{
	//node* temp = head;
	while(head!=NULL)
	{
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
}

int main()
{

	node* head = NULL;					// start with empty linkedlist. It will always be null when comes back so we take above the reference of head
	InserAtEnd(head, 6);
	InsertAtHead(head, 7);
	InsertAtHead(head, 1);
	InserAtEnd(head, 4);
	InserAfter(head->next, 8);

	print(head);
	
	return 0;
}









