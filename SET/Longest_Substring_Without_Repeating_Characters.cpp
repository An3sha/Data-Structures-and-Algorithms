
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
            if(st.count(s[j])==0)
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