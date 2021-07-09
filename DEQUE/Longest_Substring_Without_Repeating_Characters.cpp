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
            
            if(mpp[s[j]] != -1)              //check if the character at the right index exists or not
            {
            	i = max(mpp[s[j]]+1, i);
            }
            
            mpp[s[j]] = j;
            
            maxSize = max(maxSize, j-i+1);
            
            j++;
           
        }
        return maxSize;
    }
};


/*

Using SET

Time complexity : O(2n)   			:a character will be visited twice, once by r pointer (in O(n)time) and once by l pointer (in O(n)time) 
Space complexity : O(1)   */

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        set<char> st;
        int maxSize=0, i=0, j=0, n=s.size();
        while(j<n)
        {
            if(st.count(s[j])==0)                   //check if the character at the right index exists or not
            {
                st.insert(s[j]);
                maxSize = max(maxSize, j-i+1);
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return maxSize;
    }
};
