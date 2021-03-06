/* Input: s = ["h","e","l","l","o"]
   Output: ["o","l","l","e","h"] 
   
   Time Complexity : O(n)
   Space Complexity : O(1) */



class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            swap(s[i++],s[j--]);
        }
        
    }
};

/* or {
         reverse(s.begin(), s.end());
      }.  */
