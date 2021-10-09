#include<iostream>
#define ll long long int
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n, s;
		cin >> n >> s;
		ll sum = (n*(n+1))/2;
		if(s <= sum)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << sum-s << endl;
		}
	}
}