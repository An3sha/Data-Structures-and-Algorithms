#include <iostream>
#include <queue>

using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
	     freopen("1.txt", "r", stdin);
	     freopen("2.txt", "w", stdout);
	#endif

	     queue<int> q;   // Create a Queue object
	     for(int i=1;i<=5;i++)
	     {
	     	q.push(i);
	     }

	     while(!q.empty())
	     {
	     	cout<<q.front()<<endl;
	     	q.pop();
	     }

	     return 0;
}