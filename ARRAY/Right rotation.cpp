	/* Input: Array[] = {1, 3, 5, 7, 9}, K = 2.
Output: 7 9 1 3 5
Explanation:
After 1st rotation - {9, 1, 3, 5, 7}
After 2nd rotation - {7, 9, 1, 3, 5}

Input: Array[] = {1, 2, 3, 4, 5}, K = 4.
Output: 2 3 4 5 1 


Time Complexity: O(N).

Auxiliary Space: O(1).


*/


 
#include <bits/stdc++.h>
using namespace std;
 

void RightRotate(int Array[], int N, int K)
{
 
    // Reverse all the array elements
    reverse(Array, Array + N);
 
    // Reverse the first k elements
    reverse(Array, Array + K);
 
    // Reverse the elements from K
    // till the end of the array
    reverse(Array + K, Array + N);
 
    // Print the array after rotation
    for (int i = 0; i < N; i++) {
 
        cout << Array[i] << " ";
    }
 
    cout << endl;
}
 

int main()
{
 
    
    int Array[] = { 1, 2, 3, 4, 5 };
    int N = sizeof(Array) / sizeof(Array[0]);
 
    int K = 4;
 
    RightRotate(Array, N, K);
 
    return 0;
}
