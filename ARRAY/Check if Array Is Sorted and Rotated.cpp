/*  Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Time O(n)
Space O(1)

*/
class Solution {
public:
    bool check(vector<int>& nums) {
      
      int n = nums.size();
      int count = 0;
      for(int i=1; i<n; i++){
        if(nums[i]<nums[i-1]){
          count++;
        }
      }
      if(count==0)
        return true;
      if(nums[0]>=nums[n-1] && count==1)
        return true;
      
      return false;
    }
};
