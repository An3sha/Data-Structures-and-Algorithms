//DP

class solution {
  public:
      int minCostClimbingStairs(vector<int>& cost)
      {
        int n = cost.size();
        vector<int> dp(n+2);
        dp[n]=0;
        dp[n+1]=0;
        for(int i=n-1;i>=0;i--)
        {
          dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        
        return min(dp[0],dp[1]);
      }
}

/* Recursion - TLE

class Solution {
public:
    int rec(int i, vector<int> cost)
    {
        if(i>=cost.size())
            return 0;
        int op1 = rec(i+1, cost);
        int op2 = rec(i+2, cost);
        
        return min(op1, op2)+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        return min(rec(0,cost), rec(1,cost));
    }
};   */


//MEMOIZATION

class Solution {
public:
    int memo[10000];
    int rec(int i, vector<int> cost)
    {
        if(i>=cost.size())
            return 0;
        if(memo[i]!= -1)
          return memo[i];
        int op1 = rec(i+1, cost);
        int op2 = rec(i+2, cost);
        
        memo[i] = min(op1, op2)+cost[i];
        return memo[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
      
       memset(memo, -1, sizeof memo);               //for(int i=0;i<memo.size();i++)  memo[i]=-1;
        
        return min(rec(0,cost), rec(1,cost));
    }
};   
