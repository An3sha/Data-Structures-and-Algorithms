/*Time Complexity: O(n3). 
There are three nested loops traversing the array, so the time complexity is O(n^3)
Space Complexity: O(1). 
As no extra space is required.*/


class Solution{
  public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
        //Your Code Here
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    if(arr[i]+arr[j]+arr[k]==X)
                    {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};
