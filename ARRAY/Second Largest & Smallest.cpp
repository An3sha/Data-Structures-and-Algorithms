/* Example 1:
Input: [1,2,4,7,7,5]
Output: Second Smallest : 2
	Second Largest : 5
Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2

Example 2:
Input: [1]
Output: Second Smallest : -1
	Second Largest : -1 */


#include <bits/stdc++.h>
using namespace std;

void largest(int arr[], int n) {

	if (n == 0 || n == 1)
		cout << -1 << " " << -1 << endl;

	int small = INT_MAX, second_small = INT_MAX;
	int large = INT_MIN, second_large = INT_MIN;

	for (int i = 0; i < n; i++) {
		small = min(small, arr[i]);
		large = max(large, arr[i]);
	}

	for (int i = 0; i < n; i++) {

		if (arr[i] < second_small && arr[i] != small)
			second_small = arr[i];

		if (arr[i] > second_large && arr[i] != large)
			second_large = arr[i];

	}

	cout << "Second smallest is " << second_small << endl;
	cout << "Second largest is " << second_large << endl;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {1, 2, 4, 7, 7, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Array: " << "\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	largest(arr, n);
	return 0;

}

/* Time Complexity: O(N), We do two linear traversals in our array

Space Complexity: O(1) */
