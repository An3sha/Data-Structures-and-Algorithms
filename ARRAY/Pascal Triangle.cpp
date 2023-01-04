class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        for(int i=0; i<numRows; i++)
        {
            a[i].resize(i+1);
            a[i][0]=a[i][i]=1;

            for(int j=1; j<i; j++)
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }

        return a;
        
    }
};

/* 
Time Complexity = O(numRows2*numRows2)
Space Complexity: Since we are creating a 2D array, space complexity = O(numRows2*numRows2).
