vector<string> generateParenthesis(int n)
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






















