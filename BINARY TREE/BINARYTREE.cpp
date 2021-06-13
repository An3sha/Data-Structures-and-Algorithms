#include <iostream>
#include <bits/stdc++.h>
#include<queue>
using namespace std;

class node
{
	public :

	        int data;
	        node*left;
	        node*right;

	        node (int d)
	        {
	        	data = d;
	        	left = NULL;
	        	right = NULL;
	        }

};

node* buildTree()
{
	int d;
	cin >> d;
	if( d == -1)
	{
		return NULL;
	}

	node* root = new node(d);
	root -> left = buildTree();
	root -> right = buildTree();
	return root;
}

void print( node* root)
{
	if( root == NULL )
	{
		return;
	}

// otherwise print root firt followed by subtrees

	cout << root -> data << " ";
	print ( root -> left );
	print ( root -> right );
}


void printIn(node* root) //inorder
{
	if( root == NULL ){
		return;
	}

	//otherwise left root right
	printIn ( root -> left );
	cout << root -> data << " ";
	printIn ( root -> right );
}

void printPost(node* root) //postorder
{
	if( root == NULL )
	{
		return;
	}
	printPost( root -> left );
	printPost( root -> right );
	cout << root -> data << " ";
}

int height ( node* root )  // height of tree
{
	if ( root == NULL )
	{
		return 0;
	}
	int ls = height ( root -> left );
	int rs = height ( root -> right );
    return max ( ls, rs) + 1;
	
}

void printkthlevel( node *root, int k) // print kth level
{
	if ( root == NULL )
	{
		return;
	}
	if( k == 1 )
	{
		cout << root -> data << " ";
		return;
	}

	printkthlevel( root -> left, k-1 );
	printkthlevel( root -> right, k-1 );
	return;
}

void printalllevel (node* root) // print all level- level order recursive
{
	int H = height(root);
	for ( int i=1; i<=H; i++)
	{
		printkthlevel(root, i);
		cout<<endl;
	}
	return;
}

// void bfs(node* root) // 1. to print in line eg 8, 10, 3 , 1 , 6 , 14 , 9 , 7 , 13 , 
// {
// 	queue<node*> q;
// 	q.push ( root );
// 	while ( !q.empty() )
// 	{
// 		node* f = q.front();
// 		cout << f -> data << " , ";
// 		q.pop();
// 		if ( f -> left )
// 		{
// 			q.push ( f -> left );
// 		}
// 		if ( f -> right )
// 		{
// 			q.push ( f -> right );
// 		}
// 	}
// 	return;

// }

// 2. to print in levels eg    8, 
                          //  10 3
                         // 1  6  14 
                         // 9  7  13  

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

int count ( node* root)  // count the no of nodes in a tree
{
	if ( root == NULL )
	{
		return 0;
	}
	 
	return 1 + count (root -> left) + count (root -> right);
}

int sumofnodes ( node* root) // sum of nodes in a tree
{
	if ( root == NULL )
	{
		return 0;
	}
	 
	return (root -> data) +  sumofnodes(root -> left) + sumofnodes(root -> right);
}

int diameter ( node* root )  // diameter of a tree O(N^2) worst case
{
	if ( root == NULL )
	{
		return 0;
	}
	int h1 = height ( root -> left );
	int h2 = height ( root -> right );
	int op1 = h1 + h2;
	int op2 = diameter ( root -> left );
	int op3 = diameter ( root -> right );

	return max ( op1, max ( op2, op3 ));


}

class Pair {       // diameter of a tree optimized solution O(N)
	public :
	   int height;
	   int diameter;	   
};
Pair fastdiameter ( node* root )
{
	Pair p;
	if ( root == NULL )
		{
			p.diameter = p.height = 0;
			return p;
		}
		Pair left = fastdiameter ( root -> left );
		Pair right = fastdiameter ( root -> right );
		p.height = max ( left.height, right.height ) + 1;
		p.diameter = max ( left.height + right.height, max ( left.diameter, right.diameter ));
		return p;
}

int replacesum ( node* root )  // replace sum of nodes by sum of child nodes and don't change leaf nodes
{
	if ( root == NULL )
	{
		return 0 ;
	}

	if ( root -> left == NULL && root -> right == NULL )
	{
		return root -> data;
	}
	int leftsum = replacesum ( root -> left );
	int rightsum = replacesum ( root -> right );
	int temp = root -> data;
	root -> data = leftsum + rightsum;
	return temp + root -> data;
}

class HBPair {        //Height Balanced tree
	public :
	int height;
	bool balance;
};
HBPair isHeightBalance ( node* root )
{
	HBPair p;
	if ( root == NULL )
	{
		p.height = 0;
		p.balance = true;
		return p;
	}
	HBPair left = isHeightBalance ( root -> left );
	HBPair right = isHeightBalance ( root -> right );
	p.height = max ( left.height, right.height ) + 1;
	if( abs ( left.height - right.height ) <= 1 && left.balance && right.balance )
	{
		p.balance = true;
	}
	else
	{
		p.balance = false;
	}
	return p;
}

node* buildTreefromArray ( int *a, int s, int e )  //Build a tree from an array
{
	if ( s > e )
	{
		return NULL;
	}
	int mid = ( s + e )/2;
	node* root = new node ( a [ mid ]);
	root -> left = buildTreefromArray ( a, s, mid-1 );
	root -> right = buildTreefromArray ( a, mid+1, e );
	return root;
}

node* createTreefromTraversals ( int *in, int *pre, int s, int e )  //Create a tree from given preorder and inorder
{
	static int i = 0; //static variable a variable that has been allocated "statically", meaning that its lifetime is the entire run of the program
	if ( s > e)
	{
		return NULL;
	}
	node* root = new node ( pre[i] );
	int index = -1; //lets suppose because we dont know index now so lets find 
	for ( int j=s; s<=e; j++ )
	{
		if ( in[j] == pre [i] )
		{
			index = j;
			break;
		}
	}
	i++;
	root -> left = createTreefromTraversals ( in, pre, s, index-1 );
	root -> right = createTreefromTraversals ( in, pre, index+1, e );
	return root;
}



int main()
{
	#ifndef ONLINE_JUDGE
	     freopen("input.txt", "r", stdin);
	     freopen("output.txt", "w", stdout);
	#endif



	    // node* root = buildTree();
	     // print (root);
	     // cout << endl;

	     // printIn(root);
	     // cout << endl;

	     // printPost(root);
	     // cout << endl;

	     // cout << height(root) << endl;

	     // printkthlevel(root, 3);
	     // cout << endl;

	     // printalllevel(root);
	     // cout << endl;

	     // bfs ( root );
	     // cout << endl;

	     // cout << count ( root )<< endl;

	     // cout << sumofnodes ( root )<< endl;

	     // cout << diameter ( root ) << endl;

	     // Pair p = fastdiameter ( root );
	     // cout << p.height << endl;
	     // cout << p.diameter << endl;

	     // bfs ( root );
	     // cout << endl;
	     // replacesum ( root );
	     // bfs ( root );
	     // cout << endl;

	     // if ( isHeightBalance (root).balance )
	     // 	{ 
	     // 		cout << " Balanced Tree ";
	     // 		cout << endl;
	     //    }
	     //    else
	     //    	cout << " Not Balanced Tree ";
	     //        cout << endl;

	     // int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	     // int n = 7;
	     // node* root = buildTreefromArray ( a, 0, n-1 );
	     // bfs ( root );

	     int in[] = { 3, 2, 8, 4, 1, 6, 7, 5 };
	     int pre[] = { 1, 2, 3, 4, 8, 5, 6, 7 };
	     int n = sizeof(in)/sizeof(int);
	     node* root = createTreefromTraversals ( in, pre, 0, n-1 );
	     bfs ( root );


	     return 0;
}