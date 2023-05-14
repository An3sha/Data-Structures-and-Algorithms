/* Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
https://leetcode.com/problems/search-a-2d-matrix/description/
*/

//BRUTE FORCE APPROACH

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if(!matrix.size()) return false;
        int n=matrix.size();//rows no
        int m=matrix[0].size();//cols no
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
       
        return false;
        
    }
};

/*Time Complexity: O(m*n)
Space Complexity: O(1)*/

//                                                  BEST APPROACH - BINARY SEARCH
// Time: O(n) 
//Space: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int n=matrix.size();//rows no
        int m=matrix[0].size();//cols no
        int low=0;
        int high = matrix[0].size() - 1;
        while( low<n &&  high>=0)
        {
            int cur = matrix[low][high];
            if (cur == target) return true;
            if (target > cur) low++;
            else high--;
        }
    return false;
    }
};


/* ANOTHER APPROACH
Traverse using while loop till i is less than n and j is greater than equal to zero.
if mat[i][j] == 0 return true;
if greater than it means the element exists in another row therefore increment i.
if less than decrement j because this means element exist in that row only.
at end if not found return false. */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if(!matrix.size()) return false;
        int n=matrix.size();//rows no
        int m=matrix[0].size();//cols no
        int i=0; //first row
        int j = m - 1; //last column
        while( i<n &&  j>=0)
        {
            if(matrix[i][j]==target)
            
                return true;
            
            if(target<matrix[i][j])
            
                j--;
            
            else
                i++;
        }
        return false;
        
    }
};
/*    Time Complexity : O(N+M), The time complexity of the Below code is O(N+M) since the overall maximum number
    of iterations goes to N+M. Where N is the number of rows in matrix and M is the number of columns in matrix.

    Space Complexity : O(1), Constant space.*/
