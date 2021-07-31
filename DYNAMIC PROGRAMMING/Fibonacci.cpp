//General Solution using recursion

#include<iostream>
using namespace std;

int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	
	int ans = fib(n-1) + fib(n-2);
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int ans = fib(n);
	cout<<n<<th fib no. is<<ans; 		//if we try to find the 40th fib no. it'll take years(in terms of computer) to calculate the value.
}
/* Time Complexity : O(2^n)	
   Space Complexity : O(n)

				 

								     f(5) 		       ------------------------------------------ 2^0			
								  /	  \
							   	 /	   \
							        /	    \
							       /	     \
							      /		      \
							     /		       \
							    /		        \
							   /			 \
						  	  /       		  \
						        f(4)			  f(3)	        ------------------------------------------- 2^1	
						        / \			  / \
						       /   \			 /   \
						      /	    \			/     \
						     /	     \ 		       /       \
					         f(3)       f(2)            f(2)       f(1)     ------------------------------------------- 2^2
					         / \         / \	     / \        
					        /   \       /   \           /   \      
				               f(2)  f(1)  f(1) f(0)      f(1) f(0)  		------------------------------------------- 2^3
				               /  \
					      /    \
					    f(1)  f(0)						------------------------------------------- 2^4



				 Time Complexity: 2^0 + 2^1 + 2^2 + 2^3 + 2^4  = 2^n
				 Time Complexity: 2^n

*/


//OPTIMIZED SOLUTION using DYNAMIC PROGRAMMING

#include <iostream>
using namespace std;

int fib(int n)
{
	int a[n];
	int i;
	a[0]=0;
	a[1]=1;
	for(i=2; i<n; i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
	return a[i-1];
}

Time Complexity : O(n)
Space Complexity : O(n)
		


//OPTIMIZED SOLUTION using MEMOIZATION or DIVIDE & CONQUER 

#include <iostream>
using namespace std;

int memo[1000];

int fib (int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;

	if(memo[n]!= -1)
	{
		return memo[n];
	}

	int ans = fib(n-1) + fib(n-2);
	memo[n]= ans;
	return ans;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<=n; i++)
	{
		memo[i] = -1; 		//emptying my memopad
	}

	int ans = fib(n);
	cout<<n<<"th fib no. is"<<ans;
}

// Time Complexity : O(n)
