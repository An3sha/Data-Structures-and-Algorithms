/*  Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]    */


//Brute Force
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int count = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0)
		{
			count++;
		}
	}
	for (int i = 0; i < nums.size(); i++) {
		nums[i] = nums[i + count];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> nums = {0};
	cout << "Array: " << "\n";
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";
	moveZeroes(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}
