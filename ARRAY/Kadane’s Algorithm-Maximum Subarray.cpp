/*
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/


/* Naive Approach 

Time Complexity: O(N^3)

Space Complexity: O(1) 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> subarray;
        int max_sum = INT_MIN;
        int n = nums.size();
        if (n == 1)
        {
             return nums[0];
        }
        int i, j;
        for (i = 0; i <= n - 1; i++)
         {
             for (j = i; j <= n - 1; j++)
              {
                 int sum = 0;
                 for (int k = i; k <= j; k++)
                 {
                    sum = sum + nums[k];
                 }
                 
                       
                 if (sum > max_sum)
                 {
                     subarray.clear();
                     max_sum = sum;
                     subarray.push_back(i);
                     subarray.push_back(j);

                  }
              }

         }
  
        return max_sum;
    }
};

/* A better approach
Time Complexity: O(N^2) 

Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        vector<int> subarray;
        for (int i = 0; i < nums.size(); i++) {
            int curr_sum = 0;
            for (int j = i; j < nums.size(); j++) {
            curr_sum += nums[j];
            if (curr_sum > max_sum) {
                subarray.clear();
                max_sum = curr_sum;
                subarray.push_back(i);
                subarray.push_back(j);
            }
            }
        }
         return max_sum;
    }
};


/* Kadane

Time Complexity: O(N) 

Space Complexity:O(1)

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        for(auto it : nums)
        {
            sum = sum + it;
            maxsum = max(maxsum, sum);
            if(sum<0)
            {
                sum = 0;
            }
        }

        return maxsum;
        
    }
};


/* TRY USING DP */

public int maxSubArray(int[] A) {
        int n = A.length;
        int[] dp = new int[n];//dp[i] means the maximum subarray ending with A[i];
        dp[0] = A[0];
        int max = dp[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            max = Math.max(max, dp[i]);
        }
        
        return max;
}
