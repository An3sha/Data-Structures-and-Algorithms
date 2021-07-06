/* shift disc to the other stands
we have to follow 2 rules:
1. cannot place a bigger disc over a smaller disc
2. pick only 1 disc at a time */

/*
shift n-1 discs from A(src) to B(helper) using C
move the last disc from A to C(dest) (now rod 1 is empty)
move n-1 discs from B to C using A

We can solve this problem iteratively using 3 stacks as well */

#include<iostream>
using namespace std;

void hanoi(int n, char src, char dest, char helper)
{
	//Base case
	if(n==0)
	{
		return;
	}
	//Rec case - move n-1 disc from src to helper
		hanoi(n-1,src,helper,dest);

		cout<<"Move "<<n<<" disc from "<<src<<" to "<<dest<<endl;

		hanoi(n-1,helper,dest,src);
	
}

int main()
{
	#ifndef ONLINE_JUDGE
	     freopen("input.txt", "r", stdin);
	     freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	hanoi(n,'A','C','B');

	return 0;
}

