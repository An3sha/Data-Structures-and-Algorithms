/* 

Using MAP   : MOST OPTIMISED SOLUTION

Time complexity : O(n)
Space complexity : O(1) */

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> mpp(256, -1); 			// because we have 256possible characters, we can also use vector<int> mpp(char, int);
        int maxSize=0, i=0, j=0, n=s.size();
        
        while(j<n){
            
            if(mpp[s[j]] != -1)             //check if the character at the right index exists or not
            {
            	i = max(mpp[s[j]]+1, i);    //if it exists we'll take it and do +1
            }
            
            mpp[s[j]] = j;
            
            maxSize = max(maxSize, j-i+1);
            
            j++;
           
        }
        return maxSize;
    }
};


