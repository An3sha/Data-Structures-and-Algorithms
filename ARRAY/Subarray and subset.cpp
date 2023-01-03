/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]. */

class Solution {
  public:
  vactor<vector<int>> subsets(vactor<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> ans;
    int count = pow(2, n);
    
    for(int i=0; i<count; i++)
    {
      vector<int> temp;
      for(int j=0; j<n; j++)
      {
        if(i & (1<<j))
        {
          temp.push_back(nums[j]);
        }
      }
      
      ans.push_back(temp);
    }
    
    return ans;
  }
};

/* 
Time Complexity = O(2^n*n)
Space Complexity = O(1)


https://www.youtube.com/watch?v=b7AYbpM5YrE&ab_channel=takeUforward

*/
  
  
