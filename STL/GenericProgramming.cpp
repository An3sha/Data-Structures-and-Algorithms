// TEMPLATE

#include <iostream>
#include <cstring>
#include <list>
using namespace std;
template <typename T>

//Linear Search

int linearsearch ( T arr[], int n, T key )
{
	for ( int i=0; i<n; i++ ){
	{
		if ( arr[i]==key )
			return i;
	}

   }

	return n;
}

template<class ForwardIterator, class T>
//Here we have created a template function with ForwardIterator as its template parameter. This template parameter represents a type that has not yet been specified, but that can be used in the template function as if it were a regular type.
// Iterators work on all containers like template does on data types
//template <class T>
//T GetMax (T a, T b) {


ForwardIterator search ( ForwardIterator start, ForwardIterator end, T key )
//can work on different containers other than lists
{
	while ( start!=end )
	{
		if ( *start==key )
		{
			return start;
		}
		start++;
	}
	return end;

}

//Comparators gives us freedom from different types of operators operating on data 

template<class ForwardIterator, class T, class Compare>  //Templates + Iterators + Comparators
ForwardIterator search ( ForwardIterator start, ForwardIterator end, T key, Compare cmp )
{
	while ( start!=end )
	{
		if ( cmp(*start, key) )
		{
			return start;
		}
		start++;
	}
	return end;
}

class Book{
public:
	string name;
	int price;

	Book(){        //default constructor

	}

	Book(string name, int price)    //parametrised constructor
	{
		this -> name = name;
		this -> price = price;
	}
};

class BookCompare{
public:
	bool operator()(Book A, Book B){
		if(A.name == B.name)
			{
				return true;
			}
			return false;
	}
}



int main()
{
	#ifndef ONLINE_JUDGE
	     freopen("1.txt", "r", stdin);
	     freopen("2.txt", "w", stdout);
	#endif

	     // int a[]={1, 2, 3, 4, 5 };
	     // int m = sizeof(a)/sizeof(int);
	     // int k = 4;
	     
	     // cout << linearsearch (a,m,k) << endl;

	     // float b[] = { 1.1, 1.2, 1.3, 1.4 };
	     // int n = sizeof(b)/sizeof(int);
	     // float l = 1.1;
	     // cout << linearsearch (b,n,l) << endl;

	     // list<int> l;
	     // l.push_back(1);
	     // l.push_back(2);
	     // l.push_back(5);
	     // l.push_back(3);

	     //l.begin() is a iterator and it will have a data type of list<int>::iterator
	     //forwarditerator will now have list data type list<int>::iterator

	     // auto it = search (l.begin(), l.end(), 50);
	     // if(it==l.end())
	     // {
	     // 	cout << "Element not present";
	     // }
	     // else
	     // {
	     // 	cout<<*it<<endl;
	     // }

	     Book b1("C++", 100);    //old edition of book
	     Book b2("Python", 120);
	     Book b3("Java", 130);
	     Book b4(b1);

	     list<Book> l;    //if we want to work with vector simply change this to vector<Book> l;
	     l.push_back(b1);
	     l.push_back(b2);
	     l.push_back(b3);

	     Book booktoFind("C++", 110);  //new edition of book   //booktoFind is key
         BookCompare cmp;

         // list<Book>::search(l.begin(), l.end(), booktoFind, cmp);   OR

         auto it = search(l.begin(), l.end(), booktoFind, cmp)
         if(it!=l.end())
         {
         	cout<< "Book found in the library";

         }
         else
         {
         	cout<<"Not found";
         }

	     return 0;
}