/*https://leetcode.com/problems/set-matrix-zeroes/description/ */

/* Assuming all the elements in the matrix are non-negative

Time Complexity:O((N*M)*(N + M)). O(N*M)
Space Complexity:O(1)
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(), col=matrix[0].size();
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

Space Complexity: O(N)

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
