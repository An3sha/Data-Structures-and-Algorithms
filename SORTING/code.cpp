#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {


	for ( int i = 0; i < n - 1; i++)

	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j]) {
				min = j;
			}
		}

		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}

	cout << "After selection sort: " << "\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {13, 46, 24, 52, 20, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Before selection sort: " << "\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	selection_sort(arr, n);
	return 0;



}