/* Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16 */




/*Time Complexity: O(n2)
Auxiliary Space: O(1) */
class Solution{
public:	
	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    for(int i=0; i<n; i++)
	    {
	        for(int j=i+1; j<n; j++)
	        {
	            if(arr[i]+arr[j]==x)
	            {
	                return 1;
	            }
	        }
	    }
	    return 0;
	}
};


/* Method 2 using hasing more optimized 
Time Complexity: O(n). 
As the whole array is needed to be traversed only once.
Auxiliary Space: O(n). 
A hash map has been used to store array elements. */


class Solution{
  public:
  
       bool hasArrayTwoCandidates(int arr[], int n, int x) {
         
         unordered_set<int> s;
         
         for(int i=0; i<n; i++)
         {  
           int sum = x-arr[i];
           if(s.find(sum)!=s.end())
           {
             return 1;
           }
           
           s.insert(arr[i]);
         }
         
         return 0;
       }
};
           
           
	
