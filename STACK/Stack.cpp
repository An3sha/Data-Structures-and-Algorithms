#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

//Stack using C++ Standard Template Library
// It already includes push,pop,top,empty

int main()
{
	#ifndef ONLINE_JUDGE
	     freopen("input.txt", "r", stdin);
	     freopen("output.txt", "w", stdout);
	#endif

	     stack<string> s;
	     s.push("Apple");
	     s.push("Mango");
	     s.push("Orange");
	     s.push("Guava");

	     while (!s.empty())
	     {
	     	cout<<s.top()<<endl;
	     	s.pop();
	     }


	     return 0;

}
