#include<iostream>
#include<deque>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int n;
	int a[100000];
	int k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>k;

	deque<int> Q(k);

	for(int i=0;i<k;i++)
	{
		while(!Q.empty()&&a[i]>a[Q.back()])
		{
			Q.pop_back();
		}
		Q.push_back(i);
	}

	//process the remaining elements
	for(int i=0;i<n;i++)
	{
		cout<<a[Q.front()]<<" ";

		//1. Remove the elements which are not the part of the window(Contraction)

		while((!Q.empty() && (Q.front() <= i-k)))
		{
			Q.pop_front();
		}

		//2. Rempove the elements whuch are not useful and are in windows

		while(!Q.empty() && a[i]>=a[Q.back()])
		{
			Q.pop_back();
		}

		//3. Add the new elements(Expansion)
		Q.push_back(i);
	}
	cout<<a[Q.front()]<<endl;



	return 0;
}