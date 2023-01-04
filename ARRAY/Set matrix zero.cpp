/*https://leetcode.com/problems/set-matrix-zeroes/description/ */

/* Assuming all the elements in the matrix are non-negative

Time Complexity:O((N*M)*(N + M))
Space Complexity:O(1)
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {           // since it is passed by referrence (&) we don't need to return anything. The matrix itself will change
        
        int row=matrix.size(), col=matrix[0].size();        // for col, we take matrix[0] that is any row of the matrix and calculate its size which will eventually give the matrix's column size
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(matrix[i][j]==0)
                {
                    int a=i-1;
                    while(a>=0)
                    {
                        if(matrix[a][j]!=0)
                        {
                            matrix[a][j]=-1;
                        }
                        a--;
                    }

                    int b=i+1;
                    while(b<row)
                    {
                        if(matrix[b][j]!=0)
                        {
                            matrix[b][j]=-1;
                        }
                        b++;
                    }

                    int c=j-1;
                    while(c>=0)
                    {
                        if(matrix[i][c]!=0)
                        {
                            matrix[i][c]=-1;
                        }
                        c--;
                    }

                    int d=j+1;
                    while(d<col)
                    {
                        if(matrix[i][d]!=0)
                        {
                            matrix[i][d]=-1;
                        }
                        d++;
                    }
                }
            }
        }

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(matrix[i][j]==-1)

                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};






/* Better*/

/* Instead of traversing through each row and column, we can use dummy arrays to check if the particular row or column has an element 0 or not, which will improve the time complexity.

Time Complexity: O(N*M + N*M)

Space Complexity: O(M)+O(N)

 */



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(), col=matrix[0].size();
        vector<int> dummy1(row, -1), dummy2(col, -1);
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(matrix[i][j]==0)
                {
                    dummy1[i]=0;
                    dummy2[j]=0;
                }
            }
        }

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(dummy1[i]==0 || dummy2[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};



/* Optimizing the better approach

Instead of taking two dummy arrays we can use the first row and column of the matrix for the same work. This will help to reduce the space complexity of the problem. While traversing for the second time
the first row and column will be computed first, which will affect the values of further elements that’s why we traversing in the reverse direction.

Time Complexity: O(2*(N*M)), as we are traversing two times in a matrix

Space Complexity: O(1)

*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    //checking if 0 is present in the 0th column or not
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  //traversing in the reverse direction and
  //checking if the row or col has 0 or not
  //and setting values of matrix accordingly.
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols - 1; j >= 1; j--) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (col0 == 0) {
      matrix[i][0] = 0;
    }

  }

        
    }
};











