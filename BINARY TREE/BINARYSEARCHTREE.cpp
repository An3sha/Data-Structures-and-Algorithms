#include <iostream>
#include <queue>
#include <climits>
using namespace std;


class node 
{
	public :
	        int data;
	        node* left;
	        node* right;

	        node ( int d )
	        {
	        	data = d;
	        	left = NULL;
	        	right = NULL;
	        }

};

node* insertInBST ( node* root, int data ) // accepts the old root node & data and returns the new root node
{
	//base case
	if ( root == NULL )
	{
		return new node ( data );
	}
	//recursive case - insert in subtree and return pointer
	if ( data <= root -> data )
	{
		root -> left = insertInBST ( root -> left, data );

	}
	else
	{
		root -> right = insertInBST ( root -> right, data );
	}
	return root;
}



node* build()
{
    // Read a list of numbers till -1 and all thse numbers will be inserted into bst
    int d;
    cin >> d;
    node* root = NULL;
    while ( d!=-1 )
    {
    	 root = insertInBST ( root, d );
    	 cin >> d;
    }
    return root;
}

void bfs(node* root) 
{
	queue<node*> q;
	q.push ( root );
	q.push ( NULL );
	while ( !q.empty() )
	{
		node* f = q.front();
		if ( f == NULL )
		{
			cout << endl;
			q.pop ();
			if ( !q.empty() )
			{
				q.push ( NULL );
			}
		}
		else 
		{

		    cout << f -> data << "  ";
		    q.pop();
		    if ( f -> left )
		    {
			     q.push ( f -> left );
		    }
		    if ( f -> right )
		    {
			     q.push ( f -> right );
		    }

	    }

	}
	return;

}

void inorder ( node* root ) //inorder of a bst is always a sorted array
{
	if ( root == NULL )
	{
		return;
	}
	inorder ( root -> left );
	cout << root -> data << ",";
	inorder ( root -> right );
}

bool search ( node* root, int data ) // search for a number in a bst
{
	if ( root == NULL )
	{
		return false;
	}

	if ( root -> data == data )
	{
		return true;
	}
	// recursive 
	if ( data <= root -> data )
	{
		return search ( root -> left, data );
	}
	else 
		{
			return search ( root -> right, data );
		}
}

//Deletion in BST

node* deletebst ( node* root, int data)
{
	if ( root == NULL )
	{
		return NULL;
	}
	else if ( data < root -> data )
	{
		root -> left = deletebst ( root -> left, data );
		return root;
	}
	else if ( data == root -> data )
	{
		// found node to delete 3 cases

		// 1. case with 0 children - leaf node

		if ( root -> left == NULL && root -> right == NULL )
		{
			delete root;
			return NULL;
		}

		// 2. case with 1 child
		if ( root -> left != NULL && root -> right == NULL )
		{
			node* temp = root -> left;
			delete root;
			return temp;
		}
		if ( root -> right != NULL && root -> left == NULL )
		{
			node* temp = root -> right;
			delete root;
			return temp;
		}

		// 3. case with 2 children
		node* replace = root -> right;
		//find inorder successor from right subtree
		while ( replace -> left != NULL )
		{
			replace = replace -> left;
		}
		root -> data = replace -> data;
		root -> right = deletebst ( root -> right, replace -> data );
		return root;
	}

	else {
		root -> right = deletebst ( root -> right, data );
		return root;
	}

}

// CHECK IF BST OR NOT

bool isbst ( node* root, int minv=INT_MIN, int maxv=INT_MAX )
{
	if ( root == NULL )
	{
		return true;
	}
	if (root->data>=minv && root->data<=maxv && isbst(root->left, minv, root->data) && isbst(root->right, root->data, maxv))
	{
		return true;
	}
	return false;
}

//Flatten a bst - to sorted linked list 

class Linkedlist 
{
	public :
	      node* head;
	      node* tail;
};
Linkedlist flatten ( node* root )
{
	Linkedlist l;

	if ( root == NULL )
	{
		l.head = l.tail = NULL;
		return l;
	}

	// 1. Leaf node

	if ( root -> left == NULL && root -> right == NULL )
	{
		l.head = l.tail = root;
		return l;
	}
	// 2. Left is not null

	if ( root -> left != NULL && root -> right == NULL )
	{
		Linkedlist leftll = flatten ( root -> left );
		leftll.tail -> right = root;
		l.head = leftll.head;
		l.tail = root;
		return l;
	}
	// Right is not null
	if ( root -> right != NULL && root -> left == NULL )
	{
		Linkedlist rightll = flatten ( root -> right );
		root -> right = rightll.head;
		l.head = root;
		l.tail = rightll.tail;
		return l;
	}
	//Both sides are not null
	if ( root -> right != NULL && root -> left != NULL )
	{
		Linkedlist leftll = flatten ( root -> left );
		Linkedlist rightll = flatten ( root -> right );
		leftll.tail -> right = root;
		root -> right = rightll.head;
		l.head = leftll.head;
		l.tail = rightll.tail;
		return l;
	}
}


int main()
{
	#ifndef ONLINE_JUDGE
	     freopen("bstinput.txt", "r", stdin);
	     freopen("bstoutput.txt", "w", stdout);
	#endif


	     node* root = build ();
	     inorder ( root );
	     cout << endl;
	     bfs ( root );

	     // int s;
	     // cin >> s;

	     // if ( search ( root, s ))
	     // {
	     // 	cout << " PRESENT " << endl;
	     // }
	     // else
	     // {
	     // 	cout << " NOT PRESENT " << endl;
	     // }

	     // root = deletebst ( root, s );
	     // inorder ( root );
	     // cout << endl;
	     // bfs ( root );

	     // if ( isbst ( root ))
	     // {
	     // 	cout << "YES" << endl;
	     // }
	     // else
	     // {
	     // 	cout << "NO" << endl;
	     // }

	     Linkedlist l = flatten ( root );
	     node* temp = l.head;
	     while ( temp != NULL )
	     {
	     	cout << temp -> data << "-->";
	     	temp = temp -> right;
	     }

	     cout << endl;



	     return 0;
}
