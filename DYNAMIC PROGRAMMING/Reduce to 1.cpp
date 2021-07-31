#include<iostream>
#include<algorith>   //for fill algo
using namespace std;
const int inf = 1e9;

int reduce_dp(int n)
{
  int dp[10000];
  dp[0]=0;
  dp[1]=0;
  dp[2]=1;
  dp[3]=1;
  
  for(int i=4;i<=n;i++)
  {
    
     int q1=inf, q2=inf, q3=inf;
     if(n%3==0)
        q1 = 1+dp[i/3];
     if(n%2==0)
       q2 = 1+dp[i/2];
     q3 = 1+dp[i-1];
     dp[i] = min(q1, min(q2, q3));
  }
  return dp[n];
}
  
//MEMOIZATION 

int memo[10000];
int reduce(int n)
{
  if(n==1)
    return 0;
  
  int q1=inf, q2=inf, q3=inf;
  
  if(memo[n]!= -1)
  {
    return memo[n];     //because this has already been computed
  }
  
  if(n%3==0)
    q1 = 1+reduce(n/3);
   if(n%2==0)
    q2 = 1+reduce(n/2);
  q3 = 1+reduce(n-1);
  
  memo[n] = min(q1, min(q2, q3));     //memoize have to be done
  return memo[n];
}


/* GENERAL SOLUTION USING RECURSION

int reduce(int n)
{
  if(n==1)
    return 0;
  
  int q1=inf, q2=inf, q3=inf;
  if(n%3==0)
    q1 = 1+reduce(n/3);
   if(n%2==0)
    q2 = 1+reduce(n/2);
  q3 = 1+reduce(n-1);
  
  return min(q1, min(q2, q3));
}
*/


int main ()
{
  int n;
  cin>>n;
 // int ans = reduce(n);
  
  //fill(memo, memo+n+1, -1);        //for(memo=-1; memo<n+1; memo++)
  //int ans = reduce(n);
  
  int ans = reduce_dp(n);
  
  cout<<ans;
}
