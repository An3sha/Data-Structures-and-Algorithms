/* in-built function*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(begin(nums), end(nums));
    }
};

/* brute force - find all the possible permutations and then find the next one from that*/


/* Optimized

1. Linearly traverse from back and we have to find an index where:    arr[i]<arr[i+1];  i=k
2. Linearly traverse from back and we have to find an index where:    arr[i]>arr[k]; i=l
3. Swap arr[k] and arr[l]
4. Reverse array after arr[k];



*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      
      int n = nums.size(), k, l;
      for(int k=n-2; k>=0; k--)     // we will start traversing from the second last element
      {
        if(nums[k]<nums[k+1])
          break;
      }
      if(k<0)
        reverse(nums.begin(), nums.end());
      else
      { 
          for(int l=n-1; l>k; l--)
          {
            if(nums[l]>nums[k];
             
                 break;
             
           }
               swap(nums[k], nums[l]);
               reverse(nums.begin()+k+1, nums.end());   
    }
};
               /* Time complexity= O(N)
               Space Complexity= O(1)
               */
