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

/*

Time Complexity :

Let the time required for n disks is T(n) .
There are 2 recursive call for n-1 disks and one constant time operation to move a disk
from ‘from’ peg to ‘to’ peg . Let it be k1.
Therefore,
T(n) = 2 T(n-1) + k1
T(0) = k2 , a constant.
T(1) = 2 k2 + k1
T(2) = 4 k2 + 2k1 + k1
T(2) = 8 k2 + 4k1 + 2k1 + k1
Coefficient of k1 =2n
Coefficient of k2 =2n
-1
Time complexity is O(2n
) or O(an
) where a is a constant greater than 1.
So it has exponential time complexity. For single increase in problem size the time
required is double the previous one. This is computationally very expensive. Most of the
recursive programs takes exponential time that is why it is very hard to write them
iteratively .

Space Complexity:

Space for parameter for each call is independent of n i.e., constant. Let it be k .
When we do the 2nd recursive call 1st recursive call is over . So, we can reuse the space of
1st call for 2nd call . Hence ,
T(n) = T(n-1) + k
T(0) = k
T(1) = 2k
T(2) = 3k
T(3) = 4k
So the space complexity is O(n).
Here time complexity is exponential but space complexity is linear . Often there is a trade
off between time and space complexity . 

*/
