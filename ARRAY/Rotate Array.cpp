/* Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4] */

void rotatearray(int arr, int d, int n)
{
    int temp[n];               //initializing a temporary array with the same size as arr
    int k=0;                   //k is to keep the track of size of temp array
    
    for(int i=d; i<n; i++)     //storing the elements from index d to n-1 into the temp array
    {
        temp[k] = arr[i];
        k++;
    }
    
    for(int i=0; i<d; i++)      //storing the first d elements of the original array into the temp array
    {
        temp[k] = arr[i];
        k++;
    }
    
    for(int i=0; i<n; i++)      //Copying back the elements of the temp array into the original array
    {
        arr[i] = temp[i];
    }
}

/*Time complexity: O(N) 
Auxiliary Space: O(N)*/





class Solution 
    {
    public:
        void rotate(vector<int> &nums, int k) 
        {
            int n = nums.size();
            k = k%n;                                                // if k is 6 and vector size is 4 so, now k=2 bcz at k=5 array will start rotating again.
   
            reverse(nums.begin(), nums.end() - k);              // for array-  reverse(a, a+d);
        
            reverse(nums.end() - k, nums.end());                //  reverse(a+d, a+n);
         
            reverse(nums.begin(), nums.end());                  // reverse(a, a+n);
        }
    };
/* Let the array be - 123456789 and k = 4

Step 1 - 12345 6789 ---> 54321 6789

Step 2 - 54321 6789 ---> 54321 9876

Step 3 - 543219876 ---> 678912345

Time complexity: O(N) 
Auxiliary Space: O(1) */

