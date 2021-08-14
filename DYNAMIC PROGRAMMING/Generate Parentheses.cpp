int generateParenthesis(int n)
{
  int dp[n+1];
  dp[0] = 0;
  dp[1] = 1;
  
  for(int i=2; i<=n; i++)
  {
    int inside = i-1;
    int outside = 0;
    
    while(inside>=0)
    {
      dp[i] += = dp[inside]*dp[outside];
      inside--;
      outside++;
    }
  }
  return dp[n];
}

// if want ()())()) output
class Solution {
public:
    vector<string> ans;
    void f(string s,int open,int close){        //open => '(' count remaining
        if(open==0&&close==0){                  //close=> ')' count remaining
            ans.push_back(s);
            return;
        }
        if(open>0)f(s+"(",open-1,close);
        if(open<close)f(s+")",open,close-1);    //'(' must be placed before ')'
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        f("",n,n);                              //Balanced string will have
        return ans;                             //n-open and n-closing brackets
    }
};




















