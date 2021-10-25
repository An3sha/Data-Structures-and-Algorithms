/* Implement a function that returns a list of all occurrences of a given substring inside a big string. Return empty vector if smaller string is not present inside bigger string */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> stringSearch(string big, string small)
{
	vector<int> result;
	int index = big.find(small);
	while(index!=-1)
	{
		result.push_back(index);
		index = big.find(small, index+1);
	}
	return result;
}
