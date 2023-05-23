/* Time complexity: O(N2), (where N = size of the array), for the worst, and average cases.
Space Complexity: O(1)

Takes an element and places it in its correct position */

void insertion_sort(int arr[], int n) {
  for(int i=0; i<n; i++){
    int j=i;
    while(j>0 && arr[j-1]>arr[j]){
      int temp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
 cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

/* Best Case Time Complexity: 

The best case occurs if the given array is already sorted.
And if the given array is already sorted, the outer loop will only run and the inner loop will run for 0 times.
So, our overall time complexity in the best case will boil down to O(N), where N = size of the array. */
